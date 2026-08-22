class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> setnum;

        for (auto & ss : nums) {
            if (!setnum.insert(ss).second) {
                return ss;
            }
        }
        return 0;
    }
};
