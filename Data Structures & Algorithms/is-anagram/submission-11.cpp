class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<int, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        for (auto &nums : mp) {
            if (nums.second > 0)
                return false;
        }

        return true;
    }
};
