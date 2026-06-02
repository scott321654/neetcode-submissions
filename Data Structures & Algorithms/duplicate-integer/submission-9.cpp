class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
		unordered_map<int, int> mp;

		for (auto& n : nums) {
			if (mp.count(n))
				return true;
			mp[n]++;
		}
		return false;
    }
};
