class Solution {
public:
  bool isPowerOfTwo(int n) {
    /*** recursion ***/
    if (n < 1) return 0;
    if (n == 2 || n == 1) return 1;
    if (n%2 == 1) return 0;
    return isPowerOfTwo(n/2);
    /*** recursion end ***/

    /*** bit manipulation ***/
    if (n < 0) return 0;
    bitset<32> bts(n);
    return  bts.count() == 1;
    /*** bit manipulation ***/
  }
};
