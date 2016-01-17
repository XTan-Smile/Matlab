#ifndef __ERRRATE_H__
#define __ERRRATE_H__

#include <vector>

using std::vector;
double errRate(unsigned pair[][2], 
	       vector<unsigned> x1,
	       vector<unsigned> x2,
	       vector<bool> yL);
#endif
