class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);
    if (s1.size() > s2.size()) return false; 
        for (int i = 0; i < s1.size(); i++) {
           s1Count[s1[i] - 'a']++;
           s2Count[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        for (int left = 0, right = s1.size(); right < s2.size(); right++) {
            if (matches == 26)
                return true;
            int index = s2[right] - 'a';
            s2Count[index]++;

            if (s1Count[index] == s2Count[index])
                matches++;
            else if (s1Count[index] == s2Count[index] - 1)
                matches--;

            index = s2[left] - 'a';
            s2Count[index]--;

            if (s1Count[index] == s2Count[index])
                matches++;
            else if (s1Count[index] == s2Count[index] + 1)
                matches--;
            left++;
        }

        return (matches == 26);
    }
};

// use hash map to store all char 
// mp[s1[i]]++;
//while(j < s2.size()) 
//if (mp.count(s1[i]) == 0)
