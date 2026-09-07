class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (toupper(s[left]) == toupper(s[right])) {
                left++;
                right--;
            } else if (!isalnum(s[left])) {
                left++;
            } else if  (!isalnum(s[right])) {
                right--;
            } else {
                return false;
            }
        }

        return true;
    }
};
