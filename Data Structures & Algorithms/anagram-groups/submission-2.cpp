class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> frq;
        vector<vector<string>> ans;
        for (auto& s : strs)
        {
            string t = s; 
            sort(t.begin(), t.end());
            frq[t].push_back(s);
        }

        for (auto& obj : frq)
        {
            ans.push_back(obj.second);
        }

        return ans;
    }
};
