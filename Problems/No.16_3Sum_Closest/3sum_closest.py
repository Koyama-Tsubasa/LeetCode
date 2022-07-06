class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        # store some parameters
        SC3_ans = None
        diff = sys.maxint
        l_index, r_index = None, None
        
        # start compute
        nums.sort()
        for i in range(len(nums)-2):
            
            # check if the set is contained in the last set
            if (i == 0 or (i > 0 and (nums[i] != nums[i-1]))):
                
                l_index = i + 1
                r_index = len(nums) - 1
                while (l_index < r_index):
                    
                    temp_sum = nums[i] + nums[l_index] + nums[r_index]
                    if (temp_sum == target):
                        return target
                    elif (temp_sum < target):
                        while (l_index < r_index and nums[l_index] == nums[l_index+1]):
                            l_index += 1
                        l_index += 1
                    else:
                        while (l_index < r_index and nums[r_index-1] == nums[r_index]):
                            r_index -= 1
                        r_index -= 1
                    
                    # update the answer and the difference
                    if (abs(temp_sum-target) < diff):
                        diff = abs(temp_sum-target)
                        SC3_ans = temp_sum
            
        return SC3_ans
