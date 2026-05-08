class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> sum;

        for (int j = 0; j <= n; j++)
        {
            int i = 0;
            int k = j;
            
            while (k)
            {
                k &= (k - 1); 
                i++;
            }
            sum.push_back(i);
        }
        
        return sum;
    }
};
