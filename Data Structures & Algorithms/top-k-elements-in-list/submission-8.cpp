class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        vector<pair<int, int>> q;
        
        for (auto&s : mp) {
            q.push_back({s.second, s.first});
        } 
        
        sort(q.rbegin(), q.rend());
        vector<int> res;
        for (int i = 0 ; i< k;i++) {
            res.push_back(q[i].second);
        }
        return res;
    }
};