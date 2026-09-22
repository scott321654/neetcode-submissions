class Solution {
    vector<vector<int>> res;
    vector<int> subtree;

    void DFS(vector<int> &nums, int i) {
        if (i == nums.size()) {
            res.push_back(subtree);
            return;
        }

        subtree.push_back(nums[i]);
        DFS(nums, i + 1);
        subtree.pop_back();
        DFS(nums, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       DFS(nums, 0); 
       return res;
    }
};
