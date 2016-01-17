#include <vector>
#include <assert.h>
#include "matrix.h"
#include <iostream>

#define CLM 129

using std::vector;

vector<double* > vecToStar(Matrix<double> & M) {
  int row = M.getRows();
  int col = M.getColumns();
  assert(col == (int)CLM);
  vector<double* > newM;
  for(int r = 0; r < row; r++) {
    double * eachVec = new double[col];
    for(int c = 0; c < col; c++) {
      eachVec[c] = M[r][c];
    }
    newM.push_back(eachVec);
    delete eachVec;
  }
  return newM;
}

Matrix<double> starToVec(vector<double* > & M) {
  unsigned row = M.size();
  Matrix<double> newM(row, (unsigned)CLM);
  for(unsigned r = 0; r < row; r++) {
    for(unsigned c = 0; c < (unsigned)CLM; c++)
      newM[r][c] = M[r][c];
  }
  return newM;
}
