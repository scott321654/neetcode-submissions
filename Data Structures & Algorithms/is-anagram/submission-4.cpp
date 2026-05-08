class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t .size())
        //     return false;

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // for (int i = 0; i < s.size(); i++)
        // {
        //    if (s[i] != t[i])
        //    {
        //     return false;
        //    }   
        // }
        // return true;

        if (s.size() != t .size())
            return false;

        unordered_map<char, int> charmap;

        for (int i = 0; i < s.size(); i++)
        {
            charmap[s[i]]++;
            charmap[t[i]]--;
        }

        for (auto& ans : charmap)
        {
           if (ans.second > 0)
            return false;
        } 

        return true;
    }
};
