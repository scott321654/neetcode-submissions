class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int , int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }

        for (int j = 0; j < nums.size(); j++)
        {
            int diff = target - nums[j];

            if (map[diff] && (map[diff] != j))
            {
                ans.push_back(j);
                ans.push_back(map[diff]);
                return  ans;
            }
        }

        return ans;
    }
};
