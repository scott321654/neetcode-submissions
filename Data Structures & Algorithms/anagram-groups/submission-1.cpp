class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for (auto&s : strs)
        {
            string t = s;
            sort(s.begin(), s.end());
            map[s].push_back(t);
        }

        for (auto& num : map)
        {
            ans.push_back(num.second);
        }

        return ans;
    }
};
