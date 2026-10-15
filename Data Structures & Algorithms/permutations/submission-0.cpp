class Solution {
    vector<int> curr;
    vector<vector<int>> res;

    void backtrace(vector<int>& nums, vector<bool>& check) {
        if (nums.size() == curr.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (check[i] == true) continue;
            curr.push_back(nums[i]);
            check[i] = true;
            backtrace(nums, check);
            curr.pop_back();
            check[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> check(nums.size(), false);
        backtrace(nums, check);
        return res;
    }
};
