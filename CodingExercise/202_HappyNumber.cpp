#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>

using std::unordered_map;
using std::vector;
using std::set;

class Solution {
public:
  Solution () {}
  ~Solution () {}
  
public:
  bool isHappy(int n) {
    if (n <= 0) return false;
    /*** using set<int> ***/
    int sum = n;
    // using set to store the cal squared sums
    set<int> setSum;
    // if sum != 1, continue cal
    while (sum != 1) {
      sum = sSum(sum);
      // if the sum has been calculated, then n cannot be a happy number
      if (setSum.find(sum) != setSum.end()) {
	return false;
      }
      // store the sum
      setSum.insert(sum);
    }
    return true;
  }
  
  // return the squared sum for a given number
  int sSum (int n) {
    int sum = 0;
    while (n/10 > 0) {
      int temp = n%10;
      sum += temp * temp;
      n = n / 10;
    }
    sum += n * n;
    return sum;
  }
  /*** using set<int> end ***/
};

/*** method 2: using hash table, very similar to the former method ***/
  bool isHappy(int n) {
    if (n <= 0) return false;
    int sum = n;
    unordered_map<int, int> hashSum;
    while (sum != 1) {
      std::vector<int> numbers;
      numbers = integers(sum);
      sum = sSum(numbers);
      if (hashSum.find(sum) != hashSum.end()) {
	return false;
      }
      hashSum[sum] = sum;
    }
    return true;
  }
    
  vector<int> integers(int n) {
    std::vector<int> numbers;
    while (n/10 > 0) {
      numbers.push_back(n%10);
      n = n / 10;
    }
    numbers.push_back(n%10);
    return numbers;
  }
    
  int sSum (std::vector<int> vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
      sum += vec[i] * vec[i];
    }
    return sum;
    }
/*** method 2 end ***/
};

