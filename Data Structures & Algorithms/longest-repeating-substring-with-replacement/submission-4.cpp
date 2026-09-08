class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int max_freq = 0;
        int res = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < s.size(); ++right) {

            mp[s[right]]++;
            max_freq = max(max_freq, mp[s[right]]);

            while (right - left + 1 - max_freq > k) {
                mp[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }

        return res;

    }
};
