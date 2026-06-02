class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
		unordered_set<int> set_mp;

		for (auto& n : nums) {
			if (set_mp.count(n))
				return true;
			set_mp.insert(n);
		}
		return false;
    }
};