class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set_arr(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (set_arr.count(nums[i]))
                return true;
            set_arr.insert(nums[i]);
        }
        return false;
    }
};