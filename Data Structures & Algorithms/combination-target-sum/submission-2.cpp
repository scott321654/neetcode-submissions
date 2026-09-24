class Solution {
    vector<vector<int>> res;
    void DFS(vector<int> &nums, int i, int total, const int target, vector<int> &cur) {
        if (total == target) {
            res.push_back(cur);
            return;
        }
        if (total > target || i == nums.size()) {
            return;
        }
        cur.push_back(nums[i]);
        DFS(nums, i
    , total + nums[i], target, cur);
        cur.pop_back();
        DFS(nums, i + 1, total, target, cur);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        DFS(nums, 0, 0, target, cur);
        return res;
    }
};
