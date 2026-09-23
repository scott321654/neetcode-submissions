class Solution {
    vector<vector<int>> res;
    vector<int> subset;

    void DFS(vector<int> &nums, int i) {
        if (i == nums.size()) {
            res.push_back(subset);
            return ;
        }
        subset.push_back(nums[i]);
        DFS(nums, i + 1);
        subset.pop_back();
        DFS(nums, i + 1);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         DFS(nums, 0);
         return res;
    }
};
