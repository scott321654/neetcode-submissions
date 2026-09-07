class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i) {
			int fixed_val = nums[i];
			int left = i + 1;
			int right = nums.size() - 1;

			if (i > 0 && nums[i] == nums[i - 1]) continue;

			while (left < right) {

				if (-fixed_val == nums[left] + nums[right]) {

					res.push_back({fixed_val, nums[left], nums[right]});

					while (left < right && nums[left] == nums[left+1]) {
						left++;
					}
					while (left < right && nums[right] == nums[right - 1]) {
						right--;
					}

					left++;
					right--;
				} else if (-fixed_val > (nums[left] + nums[right])) {
					left++;
				} else if (-fixed_val < (nums[left] + nums[right])) {
					right--;
				}
			}

		}
		return res;
    }
};
