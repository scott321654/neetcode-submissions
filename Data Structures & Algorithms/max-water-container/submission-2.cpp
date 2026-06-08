class Solution {
public:
    int maxArea(vector<int>& heights) {
	int left = 0, right = heights.size() - 1, max_area = 0;
	
	while (left < right) {
            int width = right - left;
	    int current_area = min(heights[left], heights[right]) * width;
	    max_area = max(current_area, max_area);
	    if (heights[right] >=  heights[left]) {
	    	left++;
	    } else {
	    	right--;
	    }
	}
    return max_area;
    }
};