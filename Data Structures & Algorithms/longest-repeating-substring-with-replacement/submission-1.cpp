class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, res = 0, max_s = 0, max_frq= 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < s.size(); ++right) {
            mp[s[right]]++;
            max_frq = max(mp[s[right]], max_frq);
            // windows length - maxfrq
           while (right - left + 1 - max_frq > k) {
                mp[s[left]]--;
              left++;
           }
            res = right - left + 1;
            max_s = max(res, max_s);
        }

        return max_s;
    }
};
