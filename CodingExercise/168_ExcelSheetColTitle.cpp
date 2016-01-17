class Solution {
public:
  string convertToTitle(int n) {
    /*** 26-cimal ***/
    string s;
    while (n) {
      s.push_back('A' + (n-1)%26);
      n = (n-1)/26;
    }
    int sz = s.size();
    string ans(sz, 'A');
    for (int i = 0; i < sz; i++) {
      ans[i] = s[sz-1-i];
    }
    return ans;
    /*** 26-cimal end ***/
    /*** operator '+' overload ***/
    string s = "";
    while (n) {
      char tp = 'A' + (n-1)%26;
      n = (n-1)/26;
      s = tp + s;
    }
    return s;
    /*** operator '+' overload end ***/
  }
};
