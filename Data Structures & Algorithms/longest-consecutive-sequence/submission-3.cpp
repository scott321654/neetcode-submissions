class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_mp;
        
        for (auto &s : nums) {
            set_mp.insert(s);
        }
        
        int max_seq = 0, current_cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (set_mp.find(nums[i]-1) == set_mp.end()) {
                cout << "in" << endl;
                int j = 0;
                while (set_mp.count(nums[i]+j)) {
                    j++;
                    current_cnt++;
                    cout << "i " << i << "current_cnt " << current_cnt << endl;
                }
                max_seq = max(max_seq, current_cnt);
                current_cnt = 0;
            } 
        }       
        return  max_seq;
    }
};