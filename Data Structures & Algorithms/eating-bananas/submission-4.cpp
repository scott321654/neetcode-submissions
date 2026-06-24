class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;
        while (true) {
            long long hours = 0; // 用 long long 防止小時數相加時溢位
            for (int i = 0; i < piles.size(); i++) {
                hours += (piles[i] + k - 1) / k; 
            }
            if (hours <= h) {
                return k; // 找到第一個符合的 k，直接回傳
            }
            k++;
        }
    }
};