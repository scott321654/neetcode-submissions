class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        
        int left  = 1;
        int i = 0;
        while (i < nums.size()) {
            res[i] *= left;
            left *= nums[i];
            cout << res[i] << endl;
            i++;
        }
        
        int right = 1;
        int j =  nums.size() - 1;

        while (j >= 0) {
            res[j] *= right;
            right *= nums[j];
            j--;
        }

        return res;
    }
};
