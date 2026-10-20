class Solution {
    vector<vector<int>> res;
    vector<int> curr;

    void backTrace(vector<bool> &flag, vector<int>& nums) {
        if (nums.size() == curr.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (flag[i] == true) {
                continue;
            }
            curr.push_back(nums[i]);
            flag[i] = true;
            backTrace(flag, nums);
            curr.pop_back();
            flag[i] = false;
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);
        backTrace(flag, nums);
        return res;
    }
};
