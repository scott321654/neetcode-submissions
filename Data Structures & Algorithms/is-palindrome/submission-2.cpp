class Solution {
public:
    bool isPalindrome(string s) {
    
        if (s == "") return true;
        
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            while (left < right &&!isalnum(s[left])) left++;
            while (left < right &&!isalnum(s[right])) right--;
            if (toupper(s[left]) == toupper(s[right])) {
                left++;
                right--;  
            } else {
                return false;
            }
        }
        
        return true;
    }
};