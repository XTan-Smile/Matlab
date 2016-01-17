class Solution {
public:
  int countPrimes(int n) {
    /*** using Sieve of Eratosthenes: minus the # of non-prime numbers ***/
    if (n < 3) return 0;
    std::vector<bool> allNums(n, 1);
    int counter = n - 2;
    for (int i = 2; i < sqrt(n); i++) {         // start from the first prime number;
      if (allNums[i]) {                       // only need to test the integers less than sqrt(n)
	for (int j = i*i; j < n; j += i) {  // find out those integers which are not prime numbers
	  if (allNums[j]) {
	    allNums[j] = 0;
	    counter--;
	  }
	}
      }
    }
    return counter;
    /*** using Sieve of Eratosthenes: minus the # of non-prime numbers end ***/
        
    if (n < 2) return 0;
    int counter = 1; // counts 2
    for (int i = 3; i < n; i = i+2) {
      // check if i is a prime
      if (checkPrime(i))
	counter++;
    }
    return counter;
  }
    
  bool checkPrime(int i) {
    if (i)
      for (int it = 3; it <= sqrt(i)+1; it = it+2) {
	if (i%it == 0) return false;
      }
    return true;
  }
};
