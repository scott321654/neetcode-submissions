class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long hours = 0;
        int max = 0, res = 0;

        for (int i = 0; i < piles.size(); i++) {
            if (max < piles[i])
                max = piles[i];
        }

        int left = 1, right = max;

        while (left <= right) {
            int k = left + (right - left) / 2;
            hours = 0;
            for (int i = 0; i < piles.size();i++) {
                hours += (piles[i] + k - 1) / k;
            }
            if (hours > h) {
                left = k + 1;
            } else {
                res = k;
                right = k - 1;
            }
        }

        return res;
    }
};
