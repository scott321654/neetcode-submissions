class Solution {
public:

    string encode(vector<string>& strs) {
        string str_size;
        for(string str : strs) {
            str_size += to_string(str.size()) + "#" + str;
        }
        return str_size;      
    }

    vector<string> decode(string s) {
        vector<string> dec_strs;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            dec_strs.push_back(s.substr(i,length));
            i = j;
        }     
        
        return  dec_strs;
    }
};