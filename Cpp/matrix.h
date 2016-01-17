#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>

template<typename T>
class Matrix {
 private:
  int numRows;
  int numColumns;
  std::vector< std::vector<T> > rows;

 public:
  Matrix (): numRows(0), numColumns(0), rows() {}
  Matrix (int r, int c):  numRows(r), numColumns(c), rows(r, std::vector<T>(c)) {}

  Matrix (const Matrix<T> & rhs) {
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    rows = rhs.rows;
  }

  ~ Matrix () {}

  Matrix<T> & operator= (const Matrix<T> rhs) {
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    rows = rhs.rows;
    return *this;
  }

  int getRows() const {
    return numRows;
  }

  int getColumns() const {
    return numColumns;
  }

  const std::vector<T> & operator[](int index) const {
    assert(index >= 0);
    assert(index < numRows);
    return rows[index];
  }

  std::vector<T> & operator[](int index) {
    assert(index >= 0);
    assert(index < numRows);
    return rows[index];
  }

  bool operator==(const Matrix<T> rhs) const {
    if (numRows != rhs.numRows) return false;
    if (numColumns != rhs.numColumns) return false;
    for (int r = 0; r < numRows; r++) {
      for (int c = 0; c < numColumns; c++) {
	if(rows[r][c] != rhs.rows[r][c]) return false;
      }
    }
    return true;
  }

  Matrix<T> operator+(const Matrix<T> rhs) const {
    assert(numRows == rhs.numRows);
    assert(numColumns == rhs.numColumns);
    Matrix<T> sum(numRows, numColumns);
    for (int r = 0; r < numRows; r++)
      for (int c = 0; c < numColumns; c++)
	sum.rows[r][c] = rows[r][c] + rhs.rows[r][c];
    return sum;
  }

  Matrix<T> operator-(const Matrix<T> & rhs) const {
    assert(numRows == rhs.numRows);
    assert(numColumns == rhs.numColumns);
    Matrix<T> minus(numRows, numColumns);
    for (int r = 0; r < numRows; r++)
      for (int c = 0; c < numColumns; c++)
	minus.rows[r][c] = rows[r][c] - rhs.rows[r][c];
    return minus;
  }

  Matrix<T> operator*(const T rhs) const {
    Matrix<T> times(numRows, numColumns);
    for (int r = 0; r < numRows; r++)
      for (int c = 0; c < numColumns; c++)
	times.rows[r][c] = rows[r][c] * rhs;
    return times;
  }

template <typename S>
friend std::ostream & operator<< (std::ostream & s, const Matrix<S> & rhs);

};

template <typename T>
std::ostream & operator<< (std::ostream & s, const Matrix<T> & rhs) {
  s << "[ ";
  for (int r = 0; r < rhs.getRows(); r++) {
    s << "{";
    for (int c = 0; c < rhs.getColumns(); c++) {
      s << rhs[r][c];
      if (rhs.getColumns() != c + 1)
	s << ", ";
      else if (rhs.getRows() != r + 1)
	s << "}" << "," << std::endl;
      else 
	s << "}";
    }
  }
  s << " ]";
  return s;
}

#endif
