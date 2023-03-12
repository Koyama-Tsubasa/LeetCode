class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """

        # parameter
        id1, id2 = 0, 0
        intersection = []

        # start computing
        nums1.sort()
        nums2.sort()
        while ((id1 < len(nums1)) and (id2 < len(nums2))):
            if nums1[id1] < nums2[id2]:
                id1 += 1
            elif nums1[id1] > nums2[id2]:
                id2 += 1
            else:
                intersection.append(nums1[id1])
                id1 += 1
                id2 += 1
        
        return intersection
