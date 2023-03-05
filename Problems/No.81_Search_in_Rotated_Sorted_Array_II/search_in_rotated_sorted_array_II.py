class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """

        # parameters
        left, right, mid = 0, len(nums)-1, None

        # start computing (use Binary Search like algorithm)
        while (left <= right):
            mid = left + (right-left)//2
            if (nums[mid] == target):
                return True
            elif ((nums[left] == nums[mid]) and (nums[mid] == nums[right])):
                left += 1
                right -= 1
            elif (nums[left] <= nums[mid]):
                if ((nums[left] <= target) and (target < nums[mid])):
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if ((nums[mid] < target) and (target <= nums[right])):
                    left = mid + 1
                else:
                    right = mid - 1
            
        return False
