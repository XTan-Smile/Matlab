#ifndef __VECCALCULATION_H__
#define __VECCALCULATION_H__

#include <vector>
using std::vector;

vector<double> vecPlus(vector<double> & lhs, vector<double> & rhs);

double vecSum(vector<double> & vct);

vector<double> vecMinus(vector<double> & lhs, vector<double> & rhs);

double innerProduct(vector<double> lhs, vector<double> & rhs);

Matrix<double> outerProduct(vector<double> lhs, vector<double> rhs);

vector<double> vecTimeMtr(vector<double> & lhs, Matrix<double> & square);

vector<double> mtrTimeVec(Matrix<double> & square, vector<double> & rhs);

double distance(vector<double> vec1,
		Matrix<double> M,
		vector<double> vec2);
#endif
