class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++) {
      if (n == 0) break;
      ans += pow(2,31-i) * (n%2);
      n = n/2;
    }
    return ans;
  }
};
