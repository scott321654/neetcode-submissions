class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        
        for (int i = 0; i < strs.size(); ++i) {
            s += to_string(strs[i].size()) + '#' + strs[i];
        }
        
        return s;
    }
    
// "5#hello5#world"
    vector<string> decode(string s) {
        vector<string> res;
        
        int i = 0;
        while (i < s.size()) {
            //find the size of each string
            int j = i;
            while (s[j] != '#') {
                ++j;
            }
            
            int str_size = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1,str_size));
            i = j + str_size + 1;
        }
        
        return res;
    }
};
