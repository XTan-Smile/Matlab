#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using std::vector;

vector<unsigned> trainSet(unsigned index) {
  // read file train_costs.txt
  FILE * fp_cost = fopen("train_costs.txt", "r");
  char * line = NULL;
  size_t n_cost;
  vector<unsigned> x1;
  vector<unsigned> x2;
  vector<bool> yL;
  while (getline(&line, &n_cost, fp_cost) != -1) {
    char * temp1;
    char * temp2;
    double curr_data = strtod(line, &temp1);
    x1.push_back((int)curr_data);
    curr_data = strtod(temp1, &temp2);
    x2.push_back((int)curr_data);
    curr_data = strtod(temp2, NULL);
    if (curr_data > 0.1)
      yL.push_back(false);
    else 
      yL.push_back(true);
  }
  delete line;
  // find lines in x1
  vector<unsigned> comparePF;
  for (unsigned r = 0; r < x2.size(); r++) {
    if(x2[r] == index) {
      comparePF.push_back(x1[r]);
    }
  }
  fclose(fp_cost);
  return comparePF;
}
