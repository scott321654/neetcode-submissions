class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> charmap;
        // int i = 0;
        for (int i = 0 ; i < t.size(); i++)
        {
            charmap[s[i]]++;
            charmap[t[i]]--;
        }

        for (auto& charnum : charmap)
        {
            if (charnum.second > 0)
            {
                return false;
            }
        }

        return true;
    }
};
