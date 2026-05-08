class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        
        for (auto&key : nums)
        {
            hash_map[key]++;
            
            if (hash_map[key] > 1)
                return true;
        } 
        
        return false;
    }
};