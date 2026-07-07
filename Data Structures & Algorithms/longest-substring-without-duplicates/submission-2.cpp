class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int left = 0, right = 0;
        int max_char = 0;

        while (right < s.size()) {

            while (char_set.count(s[right])) {
                char_set.erase(s[left]);
                left++;
            } 
            char_set.insert(s[right]);
            right++;
            max_char = max(right - left, max_char);
        }

        return max_char;
    }
};
