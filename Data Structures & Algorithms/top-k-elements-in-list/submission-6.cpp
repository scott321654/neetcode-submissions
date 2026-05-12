class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        
        for (auto &num : nums) {
            hashmap[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> heap;
        
        for (auto &entry : hashmap) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<int> res;
        
        while(!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        
        return res;
    }
};
