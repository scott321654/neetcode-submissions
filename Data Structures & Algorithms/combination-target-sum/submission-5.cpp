class Solution {
    vector<vector<int>> res;
    vector<int> cur;

    void DFS(vector<int>& nums, int total, int i, int target) {
        if (total == target) {
            res.push_back(cur);
             return;

        }
        if (total > target || i == nums.size()) {
            return;
        }
        cur.push_back(nums[i]);
        DFS(nums, total + nums[i], i, target);
        cur.pop_back();
        DFS(nums, total, i + 1, target);
    }


public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        DFS(nums, 0, 0, target);
        return res;
    }
};
