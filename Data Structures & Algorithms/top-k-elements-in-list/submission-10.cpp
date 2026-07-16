class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create count base array, the maximun count must be nums.size()
        // then we walkthrough the whole array to record how many counts of each element
        unordered_map<int, int> mp;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> res(0);

        for (auto &s : nums) {
            mp[s]++;
        }

        for (auto &z : mp) {
            bucket[z.second].push_back(z.first);
        }

        for (int i = nums.size(); i >=0; i--) {
            for (auto &e : bucket[i]) {
                if (k==0)
                    break;
                res.push_back(e);
                k--;
            }
        }
        return res;
    }
};
