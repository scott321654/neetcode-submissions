class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (int i = 0; i < strs.size(); ++i) {
            vector<int> count(26,0);
            for (auto& s : strs[i]) {
                count[s - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + '#';
            }

            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> res; 

        for (auto& a : mp) {
            res.push_back(a.second);
        }

        return res;
    }
};
