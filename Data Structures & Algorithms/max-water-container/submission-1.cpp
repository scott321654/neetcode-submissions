class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0, current_area, left = 0, right = heights.size() - 1;
        
        while (left < right) {
            current_area = min(heights[left],heights[right]) * (right - left);
            max_area = max(max_area, current_area);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }

        }
        return max_area;
    }
};
