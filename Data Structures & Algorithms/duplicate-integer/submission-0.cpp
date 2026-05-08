class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for (auto &s : nums)
        {
            map[s]++;

            if (map[s] > 1) return true;
        }

        return false;
    }
};
