class Solution {
public:
  int majorityElement(vector<int>& nums) {
    /*** vote 16ms ***/
    int count = 0;
    int most = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (count == 0) {
	most = nums[i];
	count++;
      }
      else if (most == nums[i]) {
	count++;
      }
      else {
	count--;
      }
    }
    return most;
    /*** vote end ***/
    /*** using nth_element() in <algorithm> 24ms ***/
    vector<int>::iterator mid = nums.begin() + nums.size()/2;
    nth_element(nums.begin(), mid, nums.end());
    return (*mid);
    /*** using nth_element() in <algorithm> end ***/
    /*** sort 40ms ***/
    int n = nums.size();
    if (n == 1) return nums[0];
    sort(nums.begin(), nums.end());
    return nums[n/2];
    /*** sort end ***/
  }
};
