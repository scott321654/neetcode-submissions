class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for (auto &s: strs)
        {
            string temp = s;
            sort(s.begin(), s.end());
            map[s].push_back(temp);
        }

        for (auto &s : map)
        {
            ans.push_back(s.second);
        }
        return ans;
    }
};
