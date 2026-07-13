class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp; // element, count

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]))
                return true;
            mp[nums[i]]++;
        }
        return false;
    }
};