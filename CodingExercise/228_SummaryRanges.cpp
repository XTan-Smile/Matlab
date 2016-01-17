class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.size() <= 0) 
      return res;
    long stt = nums[0];
    long curr = stt;
    string str = to_string(stt);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != curr + 1) {
	if (stt != curr) {
	  str = str + "->" + to_string(curr);
	}
	res.push_back(str);
	stt = nums[i];
	str = to_string(stt);
      }
      curr = nums[i];
    }
    if (stt == curr) {
      res.push_back(str);
    }
    else {
      str = str + "->" + to_string(curr);
      res.push_back(str);
    }
    return res;
  }
};
