class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> order(nums.begin(), nums.end());
        int ans = 0;
        for (auto&s : order)
        {
            if (!order.count(s - 1))
            {
                int length = 0;
                int t = s;
                
                while (order.count(t))
                {
                    length++;
                    t++;
                }

                ans = max(length, ans);
            }
        }

        return ans;

    }
};
