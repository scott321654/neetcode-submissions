class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> asciiCode(128,0);

        int left = 0;
        int right = 0;
        int max_len = 0;

        while (right < s.size()) {
            while (left < right && asciiCode[s[right]] == 1) {
                 asciiCode[s[left]]--;
                ++left;
            }
            asciiCode[s[right]]++;
            ++right;
            max_len = max(max_len, right - left);

        }
        return max_len;
    }
};
