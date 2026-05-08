class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> ans;

        for (auto&s : nums)
        {
            map[s]++;
        }

        int max_times = 0, max_idx = 0;

        while (k)
        {
            for (auto&s : map)
            {
                if (s.second > max_times)
                {
                   max_times = s.second;
                   max_idx = s.first;
                }
            }
            
            ans.push_back(max_idx);
            map[max_idx] = 0;
            max_times    = 0;
            k--;
        }

        return ans;
    }
};
