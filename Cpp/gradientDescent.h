
#ifndef __GRADIENTDESCENT_H__
#define __GRADIENTDESCENT_H__

#include "matrix.h"

std::vector<unsigned> find(const std::vector<bool> yL,
			   std::vector<unsigned> pjRow,
			   const bool value);

std::vector<unsigned> find(std::vector<unsigned> x,
			   std::vector<unsigned> p_col);

std::vector<unsigned> find(std::vector<unsigned> x,
			   unsigned value);

std::vector<unsigned> closePoint(unsigned jNum,
			      const std::vector<unsigned> x1,
			      const std::vector<unsigned> x2,
			      const std::vector<bool> yL);

std::vector<unsigned> farPoint(unsigned jNum,
			      const std::vector<unsigned> x1,
			      const std::vector<unsigned> x2,
			      const std::vector<bool> yL);

Matrix<double> gradientDescent(Matrix<double> PF, 
			       Matrix<double> TrainF,
			       const std::vector<unsigned> x1,
			       const std::vector<unsigned> x2,
			       const std::vector<bool> yL,
			       double alpha,
			       int iterNum);

#endif
