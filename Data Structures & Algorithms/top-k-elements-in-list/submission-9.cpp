class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }    
        
        for (auto& nums : mp) {
            freq[nums.second].push_back(nums.first);
        }
        vector<int> res;
        
        for (int i = freq.size() - 1; i >=0; i-- ) {
            for (auto&s : freq[i]) {
                res.push_back(s);
                if (res.size() == k)
                    return res;
            }
        }
        
        return res;
    }
};