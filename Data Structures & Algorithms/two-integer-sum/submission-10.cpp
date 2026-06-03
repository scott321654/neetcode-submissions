class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Key: 數字本身, Value: 該數字的索引(Index)
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            
            // 1. 檢查 Map 裡面有沒有我要的另一半
            if (mp.contains(diff)) { 
                return {mp[diff], i}; // 找到了，直接回傳兩個人的索引
            }
            
            // 2. 沒找到，就把自己放進 Map，讓後面的人有機會匹配
            mp[nums[i]] = i;
            // 或者寫 mp.insert({nums[i], i}); 
            // 這裡用 [] 覆蓋也沒關係，因為如果是重複數字（如3, 3），
            // 在第二個3進來時，在步驟 1 就會被前一個3匹配成功直接 return 了！
        }
        
        return {}; // 依題目保證必有解，這行是為了編育安全
    }
};