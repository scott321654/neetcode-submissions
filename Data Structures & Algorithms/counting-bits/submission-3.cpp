class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> res;
        int cnt;
        for (int i = 0; i <= n; ++i) {
            cnt = 0;
            int j = i;
            while (j) {
                j = j & (j - 1);
                cnt++;
            }
            res.push_back(cnt);
        }

        return res;
    }
};
