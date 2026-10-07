class Solution {
    vector<vector<int>> res;
    vector<int> curr;
    void DFS(vector<int>& candidates, int target, int total, int i) {
        if (total == target) {
            res.push_back(curr);
            return;
        }

        if (total > target || i == candidates.size()) {
            return;
        }
        // while (candidates[i] == candidates[i + 1] && i < candidates.size()) {
        //     i++;
        // }
        curr.push_back(candidates[i]);
        DFS(candidates, target, total + candidates[i], i + 1);
        curr.pop_back();
        
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        DFS(candidates, target, total, i + 1);

        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        DFS(candidates, target, 0, 0);
  
        return res;

    }
};
