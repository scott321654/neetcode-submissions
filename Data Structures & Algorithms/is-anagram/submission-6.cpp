class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countStr;
        if (s.size() != t.size())
            return false;
        
        for (int i = 0; i < s.size(); i++)
        {
            countStr[s[i]]++;
            countStr[t[i]]--;
        }

        for (auto &chkMap : countStr)
        {
            if (chkMap.second != 0)
                return false;
        }

        return true;
    }
};
