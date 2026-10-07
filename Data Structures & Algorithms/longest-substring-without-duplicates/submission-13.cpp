class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;

        int left = 0;
        int right = 0;
        int max_len = 0;

        while (right < s.size()) {
            while (left < right && mp.count(s[right])) {
                mp.erase(s[left]);
                ++left;
            }
            mp.insert(s[right]);
            ++right;
            max_len = max(max_len, right - left);

        }
        return max_len;
    }
};
