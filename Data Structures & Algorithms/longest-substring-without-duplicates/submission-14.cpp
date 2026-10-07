class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int right = 0;
        int max_len = 0;

        while (right < s.size()) {
            while (left < right && mp[s[right]] == 1) {
                mp[s[left]]--;
                ++left;
            }
            mp[s[right]]++;
            ++right;
            max_len = max(max_len, right - left);

        }
        return max_len;
    }
};
