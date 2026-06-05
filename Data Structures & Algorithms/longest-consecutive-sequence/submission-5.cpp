
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_mp;
        
        for (auto &s : nums) {
            set_mp.insert(s);
        }
        
        int max_seq = 0, current_cnt = 0;
        
        for (auto &num : set_mp) {
                int current_num = 0;
                while (set_mp.count(num + current_num)) {
                    current_cnt++;
                    current_num++;
                }
            max_seq = max(max_seq, current_cnt);
            current_cnt = 0;
        }       
        return  max_seq;
    }
};
