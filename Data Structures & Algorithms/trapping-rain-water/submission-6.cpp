class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int res = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(height[left], leftMax);
                res += leftMax - height[left];
            } else {
                right--;
                rightMax = max(height[right], rightMax);
                res += rightMax - height[right];
            }
        }
        return res;
    }
};