class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, end = s.size() - 1;

		while (front < end) {
			if (!isalnum(s[front])) {
				front++;
			} else if (!isalnum(s[end])) {
				end--;
			} else {
				if (toupper(s[front]) != toupper(s[end]))
					return false;
				front++;
				end--;
			}
		}
		return true;
    }
};
