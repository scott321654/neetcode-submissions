class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frq;
        vector<int> ans;
        int max_count = 0, max_idx = 0;

        for (auto& s : nums)
        {
            frq[s]++;
        }

        while(k)
        {
            for (auto& count : frq)
            {
                if (count.second > max_count)
                {
                    max_count = count.second;
                    max_idx = count.first;
                }
            }
            ans.push_back(max_idx);
            max_count = 0;
            frq[max_idx] = 0;
            k--;
        }

        return ans;
    }
};
