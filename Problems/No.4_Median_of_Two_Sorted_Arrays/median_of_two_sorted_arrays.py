class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        """
        O(log(m+n)), Optimal solution with binary search
        
        len1, len2 = len(nums1), len(nums2)
        def getKthElement(k):
            index1, index2 = 0,0
            while True:
                if index1 == len1:
                    return nums2[index2 + k - 1]
                if index2 == len2:
                    return nums1[index1 + k - 1]
                if k == 1:
                    return min(nums1[index1], nums2[index2])
                
                nextindex1 = min(index1 + k // 2 - 1, len1 - 1)
                nextindex2 = min(index2 + k // 2 - 1, len2 - 1)
                pivot1, pivot2 = nums1[nextindex1], nums2[nextindex2]
                if pivot1 <= pivot2:
                    k -= nextindex1 - index1 + 1
                    index1 = nextindex1 + 1
                else:
                    k -= nextindex2 - index2 + 1
                    index2 = nextindex2 + 1
                
                
    
        total_length = len(nums1) + len(nums2)
        if total_length % 2 == 1:
            return getKthElement((total_length // 2) + 1)
        else:
            return (getKthElement(total_length // 2) + getKthElement(total_length // 2 + 1)) / 2
        
        """
        
        # O(m+n), merge sort with early stop
        # parameters
        pre, cur = 0, 0
        i, mid = 0, None
        n1_index, n2_index = 0, 0
        n1_len, n2_len = len(nums1), len(nums2)
        
        # start compute
        mid = (n1_len + n2_len)/2
        while (i<=mid and n1_index<n1_len and n2_index<n2_len):
            pre = cur
            if (nums1[n1_index] <= nums2[n2_index]):
                cur = nums1[n1_index]
                n1_index += 1
            else:
                cur = nums2[n2_index]
                n2_index += 1
            i += 1
        
        while (i<=mid and n1_index<n1_len):
            pre = cur
            cur = nums1[n1_index]
            n1_index += 1
            i += 1
        
        while (i<=mid and n2_index<n2_len):
            pre = cur
            cur = nums2[n2_index]
            n2_index += 1
            i += 1
            
        if ((n1_len+n2_len)%2):
            return cur
        else:
            return (pre+cur)/2.0
        
