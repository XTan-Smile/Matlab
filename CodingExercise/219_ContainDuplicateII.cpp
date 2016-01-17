class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    /*** hash table ***/
    std::unordered_map<int, int> hash;
    std::vector<int>::iterator it;
    std::unordered_map<int, int>::iterator it_map;
    int counter = 0;
    for (it = nums.begin(); it != nums.end(); it++, counter++) {
      it_map = hash.find(*it);
      if (it_map != hash.end()) {
	if (counter - hash[*it] <= k) {
	  return 1;
	}
      }
      hash[*it] = counter;
    }
    return 0;
    /*** hash table end ***/
  }
};
