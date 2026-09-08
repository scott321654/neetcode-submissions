class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> setMp;
        int left = 0, max_length = 0;

        for (int right = 0; right < s.size(); ++right) {
            while (setMp.count(s[right])) {
                setMp.erase(s[left]);
                left++;
            } 
            setMp.insert(s[right]);

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
  