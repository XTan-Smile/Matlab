#ifndef __INTERFACE_H__
#define __INTERFACE_H__

using std::vector;

vector<double* > vecToStar(Matrix<double> & M);
Matrix<double> starToVec(vector<double* > & M);

#endif
