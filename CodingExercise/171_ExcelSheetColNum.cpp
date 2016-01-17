class Solution {
public:
  int titleToNumber(string s) {
    /*** 8ms ***/
    int ans = 0;
    int len = s.size();
    if (len > 0) {
      for (int i = 0; i < len; i++) {
	ans = ans * 26 + (s[i] - 'A' + 1);
      }
    }
    return ans;
    /*** 8ms end ***/
    /*** straight forward, calling function pow() 8ms ***/
    int ans = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
      ans += (s[i] - 'A' + 1) * pow(26, len-1-i);
    }
    return ans;
    /*** calling function pow() end ***/
  }
};
