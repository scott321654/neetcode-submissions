class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size() + nums2.size());
        int i = 0, j = 0, k = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            ans[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
        }

        while (i < nums1.size())
        {
            ans[k++] = nums1[i++];
        }

        while (j < nums2.size())
        {
            ans[k++] = nums2[j++];
        }
    
        k = 0;
        int mid = (nums1.size() + nums2.size() - 1) / 2;
        double median = ((nums1.size() + nums2.size()) % 2 != 0) ? ans[mid] : (double)(ans[mid] + ans[mid + 1]) / 2.0;

        return median;
    }
};
