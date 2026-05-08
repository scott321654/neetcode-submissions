class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frq_hash;
        
        for (int i = 0; i< nums.size(); i++) {
            frq_hash[nums[i]]++;
        }
        
        int max_freq = 0, max_id=0;
        vector<int> result;
        while (k) {
            for (auto &answer : frq_hash) {
                if (answer.second > max_freq) {
                    max_freq = answer.second;
                    max_id = answer.first;
                } 
            }
            result.push_back(max_id);
            frq_hash[max_id] = 0;
            max_id = 0;
            max_freq = 0;
            k--;
        }
        
        return result;
    }
};
