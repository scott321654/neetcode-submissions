class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size() && s.size() != 0)
        {
            return false;
        }
        unordered_map<char, int> charMap;

        for (int i = 0; i < s.size() ;i++)
        {
            charMap[s[i]]++;
            charMap[t[i]]--;
        }

        for (auto&s : charMap)
        {
            if (s.second != 0)
                return false;
        }

        return true;
    }
};
