class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*koko should fininshed piles of banana in target hour
          I will divide all elements by k to find the k is smaller tareget hour
          blute force, divide one to maximum number to find out which is best 
        */
        long long hours = 0, k = 1, res;
        while (true) {
            hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += (piles[i] + k - 1) / k; 
            }
            if (hours <= h) {
                return k;
            } 
            
            k++;
        }
        
        return res;
    }
};
