class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // I want to show you hashSET solution 
        // sliding window 
        // move right pointer and chk if the char in the map or not 
        // yes, evict duplicate one and  move left to next pointer
        int left = 0, right = 0;
        int size = s.size();
        unordered_set<char> mp;
        int max_length = 0;

        while (right < size) {
            while (mp.count(s[right])) {
                mp.erase(s[left]);
                left++;
            }

            mp.insert(s[right]);
            right++;
            max_length = max(max_length, right - left);
        }
        return max_length;
    }
};
