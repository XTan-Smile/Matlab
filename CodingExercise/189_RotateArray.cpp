class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    /*** 24ms ***/
    int n = nums.size();
    if (!n) return;
    int step = k % n;
    if (step) {
      vector<int> temps;
      // store the last n-k elements
      for (int i = n-step; i < n; i++) {
	temps.push_back(nums[i]);
      }
      // move the first k elements
      for (int i = n-step-1, j = n-1; i >= 0; i--, j--) {
	nums[j] = nums[i];
      }
      // move the stored elements
      for (int i = 0; i < temps.size(); i++) {
	nums[i] = temps[i];
      }
    }
    
    /*** 72ms ***/
    int n = nums.size();
    if (!n) return;
    int step = k % n;
    vector<int>::iterator it = nums.begin();
    while(step) {
      int temp = nums.back();
      nums.pop_back();
      nums.emplace(it, temp);
      step--;
    }
    
    /*** 24ms ***/
    int n = nums.size();
    if (!n) return;
    int step = k % n;
    if (step) {
      vector<int> temps(step,0);
      for (int i = step; i > 0; i--) {
	temps[step-i] = nums[n-i];
      }
      temps.resize(n,0);
      for (int i = 0; i < n-step; i++) {
	temps[i+step] = nums[i];
      }
      nums = temps;
    }
  }
};
