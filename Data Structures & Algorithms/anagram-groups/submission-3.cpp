class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str_hashmap;
        
        for (auto& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());  
            str_hashmap[tmp].push_back(str);
        }
        
        vector<vector<string>> result;
        
        for (auto& pair : str_hashmap) {
            result.push_back(pair.second);
        }
        
        return result;
        
    }
};
