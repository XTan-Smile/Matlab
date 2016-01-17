class Solution {
public:
  int trailingZeroes(int n) {
    /*** recursion 0ms ***/
    if (n <= 0) return 0;
    return n/5 + trailingZeroes(n/5);
    /*** recursion end ***/
    /*** loop 4ms ***/
    if (n <= 0) return 0;
    int ans = 0;
    while(n) {
      ans += n/5;
      n = n/5;
    }
    return ans;
    /*** loop end ***/
  }
};
