class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set_mp;

		for (auto&num : nums) {
			if (set_mp.insert(num).second == false)
				return true;
		}
		
		return false;
    }
};