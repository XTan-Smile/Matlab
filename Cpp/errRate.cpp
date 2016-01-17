#include <iostream>
#include <vector>
#include "matrix.h"
#include "vecCalculation.h"

#define LENGTH 500

using std::vector;

double errRate(unsigned pair[][2], vector<unsigned> x1, vector<unsigned> x2, vector<bool> yL) {
  vector<double> classLabels(LENGTH, 0);
  for(unsigned r = 0; r < LENGTH; r++) {
    for(unsigned line = 0; line < x1.size(); line++) {
      if(pair[r][0] == x1[line] && pair[r][1] == x2[line])
      {
	if(yL[line] == false) classLabels[r] = 1;
	else classLabels[r] = 0;
        break;
      }
      else {
	if((line + 1) == x1.size()) {
	  std::cout << "for pair[" << r << "], no such pairs." << std:: endl;
	  classLabels[r] = 1;
	}
      }
    }
  }
  return vecSum(classLabels) / double(LENGTH);
}
