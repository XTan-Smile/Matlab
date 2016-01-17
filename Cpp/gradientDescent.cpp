#include <vector>
#include <iostream>
#include <stdlib.h>
#include "matrix.h"
#include "gradientDescent.h"
#include "vecCalculation.h"

#define FEATURE_LENGTH 129

double hinge(double x) {
  if (x > 0) return x;
  else return 0;
}

Matrix<double> gradientDescent(Matrix<double> PF, 
			       Matrix<double> TrainF,
			       const std::vector<unsigned> x1,
			       const std::vector<unsigned> x2,
			       const std::vector<bool> yL,
			       double alpha,
			       int iterNum) {
  Matrix<double> M(FEATURE_LENGTH, FEATURE_LENGTH);
  // M = identity
  for (int i = 0; i < FEATURE_LENGTH; i++) {
    M[i][i] = 1;
  }
  Matrix<double> zeroM(FEATURE_LENGTH, FEATURE_LENGTH);
  // parameter initialziation
  Matrix<double> grad(M.getRows(), M.getColumns());
  std::vector<double> pj(PF.getColumns(), 0);
  std::vector<double> penaltyTotal(PF.getRows(), 0);
  std::vector<double> J(iterNum, 0);
  // iteration
  for (int iter = 0; iter < iterNum; iter++) {
    std::cout << "iter = " << iter + 1 <<std::endl; // TEST-LINE
    grad = zeroM;
    // for each pj in PF
    for (int jNum = 0; jNum < PF.getRows(); jNum++) {
      pj = PF[jNum];
      std::vector<unsigned> closeP = closePoint(jNum, x1, x2, yL);
      std::vector<unsigned> farP = farPoint(jNum, x1, x2, yL);
      std::vector<double> penalty(closeP.size(),0);
      // for each xi corresponding to pj
      if (!closeP.empty()) {
	for (int ii = 0; ii < int(closeP.size()); ii++) {
	  //calculate penalty for each xi in closeP
	  std::vector<double> xi = TrainF[int(closeP[ii])];
	  double penalty_xi = distance(vecMinus(pj, xi), M, vecMinus(pj, xi));
	  std::vector<double> penalty_xl_it(int(farP.size()), 0);
	  for (int ll = 0; ll < int(farP.size()); ll++) {
	    std::vector<double> xl = TrainF[int(farP[ll])];
	    penalty_xl_it[ll] = hinge(1 + penalty_xi - distance(vecMinus(pj, xl), M, vecMinus(pj, xl)));
	    if (penalty_xl_it[ll] > 0) {
	      grad = grad + outerProduct(vecMinus(pj, xi),vecMinus(pj, xi)) - outerProduct(vecMinus(pj, xl),vecMinus(pj, xl));
	    }
	  }
	  grad = grad + outerProduct(vecMinus(pj, xi),vecMinus(pj, xi));
	  double penalty_xl = vecSum(penalty_xl_it);
	  penalty[ii] = penalty_xi + penalty_xl;
	}
      }
      penaltyTotal[jNum] = vecSum(penalty);
    }
    M = M - grad * alpha;
    J[iter] = vecSum(penaltyTotal);
    std::cout << "The current total loss is: "<< J[iter] << std::endl;
  }
  return M;
}

std::vector<unsigned> find(const std::vector<bool> yL,
			   std::vector<unsigned> pjRow,
			   const bool value) {
  std::vector<unsigned> p_col;
  for (unsigned i = 0; i < pjRow.size(); i++) {
    //    if(yL.at(pjRow.at(i)) == value)
    if (yL[pjRow[i]] == value)
      p_col.push_back(pjRow[i]);
  }
  return p_col;
}

std::vector<unsigned> find(std::vector<unsigned> x,
			   std::vector<unsigned> p_col) {
  std::vector<unsigned> fc_P;
  for(unsigned i = 0; i < p_col.size(); i++) {
    fc_P.push_back(x[p_col[i]]);
  }
  return fc_P;
}

std::vector<unsigned> find(std::vector<unsigned> x,
			   unsigned value) {
  std::vector<unsigned> pj;
  unsigned xRow = 0;
  for( ; xRow < x.size(); xRow++) {
    if (x[xRow] == value) {
      pj.push_back(xRow);
    }
  }
  return pj;
}

std::vector<unsigned> closePoint(unsigned jNum,
			      const std::vector<unsigned> x1,
			      const std::vector<unsigned> x2,
			      const std::vector<bool> yL) {
  std::vector<unsigned> pjRow = find(x1, jNum);
  std::vector<unsigned> closeP_col = find(yL, pjRow, true);
  std::vector<unsigned> closeP = find(x2, closeP_col);
  return closeP;
}

std::vector<unsigned> farPoint(unsigned jNum,
			      const std::vector<unsigned> x1,
			      const std::vector<unsigned> x2,
			      const std::vector<bool> yL) {
  std::vector<unsigned> pjRow = find(x1, jNum);
  std::vector<unsigned> farP_col = find(yL, pjRow, false);
  std::vector<unsigned> farP = find(x2, farP_col);
  return farP;
}
