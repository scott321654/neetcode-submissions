class Solution {
public:
    /*empty string */
    // "I, Love, you"
    // "1I4Love3you" x
    // "1#I4#Love3#you" o
    string encode(vector<string>& strs) {
        string ret;
        for (int i = 0; i < strs.size(); i++) {
            ret += to_string(strs[i].size()) + '#' + strs[i];
        }
        cout << ret << endl;
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> dec_strs;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int str_length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + str_length;
            dec_strs.push_back(s.substr(i, str_length));
            i = j;
        }
        return dec_strs;
    }
};
