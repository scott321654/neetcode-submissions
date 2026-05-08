class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet(nums.begin(), nums.end());
        int length_max = 0;

        for (auto &s : numsSet)
        {
            if (!numsSet.count(s - 1))
            {
                int length = 0;
                int t = s;
                while (numsSet.count(t))
                {
                    t++;
                    length++;
                }

                length_max = max(length, length_max);
                length = 0;
            }
        }

        return length_max;
    }
};
