class Solution {
public:
    string encode(vector<string>& strs) {
        string s;
        for (int i = 0; i < strs.size(); i++) {
            int size = strs[i].size();
           // for (auto& ch : strs[i]) {
            s += to_string(size) + '#' + strs[i];// to_string(ch);
          //  }
        }    
        cout << s << endl;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j+ 1, length));
            i = j + 1 + length;
        }
        return res;
    }
};
