class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        std::unordered_map< char, int> hash_map;
        
        for (auto&key : s)
        {
            hash_map[key]++;
        }
        for (auto&key : t)
        {
            hash_map[key]--;
        }
        for (auto&key : hash_map)
        {
            if (key.second != 0)
                return false;
        }
        return true;
    }
};
