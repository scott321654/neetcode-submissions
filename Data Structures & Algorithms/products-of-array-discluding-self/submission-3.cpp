class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        /* nums       | 1| 2|4|6|
        /* ans:       |48|24|12|8| */

        /*prefix  res | 1| 1|2|8|*/ 
        /*suffix  res |48|24|6|1|*/
        int left_base = 1, i = 0;
        while (i < nums.size()) {
            res[i] *= left_base;
            left_base *= nums[i];
            i++;
        }
        for (auto& x: res)
        {
            cout << x << " ";
        }
cout << endl;
        int right_base = 1, j = nums.size() - 1;
        while (j >= 0) {
            res[j] *= right_base;
            cout << res[j] << " ";
            right_base *= nums[j];
            j--;
        }
        return res;
    }
};
