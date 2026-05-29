class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int> set_mp(nums.begin(), nums.end());
        int max = 0;
		for (auto &num : nums) {
			if (set_mp.find(num - 1) == set_mp.end()) {
				int current_num = num, seq = 0;
				while (set_mp.find(current_num) != set_mp.end()) {
					seq++;
					current_num++;
				}
			    max = (seq > max) ? seq : max;
			}
		}

		return max;
    }
};