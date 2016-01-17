class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
      return 0;
    }
    /*** quick sort ***/
    // sort
    int i = 0;
    int j = n;
    vector<int> curr_nums = nums;
    quick_sort(curr_nums, i, j-1);
    // compare
    for (int i = 0; i < n-1; i++) {
      if (curr_nums[i] == curr_nums[i+1]) {
	return 1;
      }
    }
    return 0;
  }
    
  void quick_sort(vector<int>& curr_nums, int left, int right) {
    int i = left;
    int j = right;
    int temp;
    int pivot = curr_nums[(left + right) / 2];
    // partition
    while (i <= j) {
      while (curr_nums[i] < pivot) {
	i++;
      }
      while (curr_nums[j] > pivot) {
	j--;
      }
      if (i <= j) {
	temp = curr_nums[i];
	curr_nums[i] = curr_nums[j];
	curr_nums[j] = temp;
	i++;
	j--;
      }
    }
    // recursion
    if (left < j)   quick_sort(curr_nums, left, j);
    if (right > i)  quick_sort(curr_nums, i, right);
    /*** quick sort end ***/
    /*** sort, & compare ***/
    // sort
    std::sort(nums.begin(), nums.end());
    //compare
    std::vector<int>::iterator it = nums.begin();
    int temp = *it;
    it++;
    for ( ;it != nums.end(); it++) {
      if (temp == *it) {
	return 1;
      }
      temp = *it;
    }
    return 0;
    /*** sort, & compare end ***/
    /*** sort, unique, resize & compare size ***/
    int pri = nums.size();
    // sort
    sort(nums.begin(), nums.end());
    // erase
    std::vector<int>::iterator it = unique(nums.begin(), nums.end());
    //resize
    nums.resize(std::distance(nums.begin(), it));
    return (nums.size() == pri) ? 0 : 1;
    return 0;
    /*** sort, unique, resize, erase, & compare size end ***/
    /*** sort , unique, erase, & compare size ***/
    int pri = nums.size();
    // sort
    sort(nums.begin(), nums.end());
    // unique
    std::vector<int>::iterator it = unique(nums.begin(), nums.end());
    // erase
    nums.erase(it, nums.end());
    // compare
    int post = nums.size();
    return (post == pri) ? 0 : 1;
    return 0;
    /*** sort , unique, erase, & compare size end ***/
    /*** hashMap ***/
    std::unordered_map<int, int> hash;
    std::vector<int>::iterator it;
    for (it = nums.begin(); it != nums.end(); it++) {
      if (hash.find(*it) != hash.end()) {
	return 1;
      }
      hash[*it] = std::distance(nums.begin(), it);
    }
    return 0;
    /*** hashMap end ***/
  }
};
