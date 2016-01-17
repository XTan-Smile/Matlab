#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <assert.h>
#include "matrix.h"

using std::vector;

vector<double> vecPlus(vector<double> & lhs, vector<double> & rhs) {
  assert(lhs.size() == rhs.size());
  vector<double> sumv(int(lhs.size()), 0);
  for (int i = 0; i < int(lhs.size()); i++) {
    sumv[i] = lhs[i] + rhs[i];
  }
  return sumv;
}

double vecSum(vector<double> & vct) {
  double sum = 0;
  for (int i = 0; i < int(vct.size()); i++) {
    sum += vct[i];
  }
  return sum;
}

vector<double> vecMinus(vector<double> & lhs, vector<double> & rhs) {
  assert(lhs.size() == rhs.size());
  vector<double> minus(int(lhs.size()), 0);
  for (int i = 0; i < int(lhs.size()); i++) {
    minus[i] = lhs[i] - rhs[i];
  }
  return minus;
}

double innerProduct(vector<double> lhs, vector<double> & rhs) {
  assert(lhs.size() == rhs.size());
  double product = 0;
  for (int i = 0; i < int(lhs.size()); i++) {
    product += lhs[i] * rhs[i];
  }
  return product;
}

Matrix<double> outerProduct(vector<double> lhs, vector<double> rhs) {
  assert(lhs.size() == rhs.size());
  int n = int(lhs.size());
  Matrix<double> product(n,n);
  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n; col++) {
      product[row][col] = lhs[row] * rhs[col];
    }
  }
  return product;
}

vector<double> vecTimeMtr(vector<double> & lhs, Matrix<double> & square) {
  assert(square.getRows() == square.getColumns());
  assert(int(lhs.size()) == square.getRows());
  vector<double> product(square.getColumns(), 0);
  for (int col = 0; col < square.getColumns(); col++) {
    for (int row = 0; row < square.getRows(); row++)
      product[col] += lhs[row] * square[row][col];
  }
  return product;
}

vector<double> mtrTimeVec(Matrix<double> & square, vector<double> & rhs) {
  assert(square.getRows() == square.getColumns());
  assert(int(rhs.size()) == square.getRows());
  vector<double> product(int(rhs.size()), 0);
  for (int row = 0; row < square.getColumns(); row++) {
    product[row] = innerProduct(square[row], rhs);
  }
  return product;
}

double distance(vector<double> vec1,
		Matrix<double> M,
		vector<double> vec2) {
  return innerProduct(vecTimeMtr(vec1, M), vec2);
}
