class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        /*
        O(log(m+n)), Optimal Solution with binary search
        
        // make sure that nums1.length() < nums2.length()
        int n1_len = nums1.size(), n2_len = nums2.size();
        if (n1_len > n2_len) return findMedianSortedArrays(nums2, nums1);
        
        // parameters
        int left = 0, right = n1_len;
        int partition_n1, partition_n2;
        int right_min_n1, left_max_n1, right_min_n2, left_max_n2;
        
        // start compute
        while (left <= right) {
            
            partition_n1 = (left + right)/2;
            partition_n2 = (n1_len + n2_len + 1)/2 - partition_n1;
            
            left_max_n1 = (partition_n1-1<0) ? INT_MIN : nums1[partition_n1 - 1];
            right_min_n1 = (partition_n1==n1_len) ? INT_MAX : nums1[partition_n1];
            
            left_max_n2 = (partition_n2-1<0) ? INT_MIN : nums2[partition_n2 - 1];
            right_min_n2 = (partition_n2==n2_len) ? INT_MAX : nums2[partition_n2];
            
            if (left_max_n1<=right_min_n2 and left_max_n2<=right_min_n1 ) break;
            if (left_max_n1 > right_min_n2) right = partition_n1 - 1;
            if (left_max_n2 > right_min_n1) left = partition_n1 + 1;
            
        }
        
        if ((n1_len+n2_len)%2) return max(left_max_n1, left_max_n2);
        else return (max(left_max_n1, left_max_n2) + min(right_min_n1, right_min_n2))/2.0;
        
        */
        
        // O(m+n), merge sort with early stop
        // parameters
        double pre, cur = 0;
        int i, mid;
        int n1_index = 0, n2_index = 0;
        int n1_len = nums1.size(), n2_len = nums2.size();
        
        // start compute
        mid = (n1_len+n2_len)/2;
        for (i=0; i<=mid and n1_index<n1_len and n2_index<n2_len; i++) {
            
            pre = cur;
            if (nums1[n1_index] <= nums2[n2_index]) cur = nums1[n1_index++];
            else cur = nums2[n2_index++];
            
        }
        
        for (; i<=mid and n1_index<n1_len; i++) {
            
            pre = cur;
            cur = nums1[n1_index++];
            
        }
        for (; i<=mid and n2_index<n2_len; i++) {
            
            pre = cur;
            cur = nums2[n2_index++];
            
        }
        
        if ((n1_len+n2_len)%2) return cur;
        else return (pre+cur)/2;
        
    }
};
