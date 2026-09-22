class Solution {
    
    vector<vector<int>> res;
    vector<int> subset;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

private:
    void dfs(const vector<int>& nums, int i) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1);
        subset.pop_back();
        dfs(nums, i + 1);
    }
};