class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        std::unordered_map< char, int> hash_map;
#if 0        
        for (auto&key : s)
        {
            hash_map[key]++;
        }
        for (auto&key : t)
        {
            hash_map[key]--;
        }
#else
        for (int i = 0; i < s.size(); i++)
        {
            hash_map[t[i]]++;
            hash_map[s[i]]--;
        }
#endif
        for (auto&key : hash_map)
        {
            if (key.second != 0)
                return false;
        }
        return true;
    }
};
