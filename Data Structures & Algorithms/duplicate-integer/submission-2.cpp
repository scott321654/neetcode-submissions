class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_map<int , int> map;

        for (auto & s : nums)
        {
            map[s]++;
        }

        for (auto& q : map)
        {
            if (q.second > 1)
            {
                return true;
            }
        }

        return false;
    }
};
