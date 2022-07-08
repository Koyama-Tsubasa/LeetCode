class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        # store some parameters
        target_3sum, target_2sum = None, None
        nums_len = len(nums)
        l_index, r_index = None, None
        fS_ans = []
        
        # preprocess
        if (nums_len < 4):
            return fS_ans
    
        # start compute
        nums.sort()
        for first in range(nums_len-3):
            
            # remove duplicates
            if (first>0 and nums[first]==nums[first-1]):
                continue
            
            # do 3Sum
            target_3sum = target - nums[first]
            for tS in range(first+1, nums_len-2):
                
                # remove duplicates
                if (tS>first+1 and nums[tS]==nums[tS-1]):
                    continue
                
                target_2sum = target_3sum - nums[tS]
                l_index = tS + 1
                r_index = nums_len - 1
                
                while (l_index < r_index):
                    if (nums[l_index] + nums[r_index] < target_2sum):
                        l_index += 1
                    elif (nums[l_index] + nums[r_index] > target_2sum):
                        r_index -= 1
                    else:
                        
                        # found the target
                        fS_ans.append([nums[first], nums[tS], nums[l_index], nums[r_index]])
                        
                        # remove duplicates
                        l_index += 1
                        while (l_index<r_index and nums[l_index-1]==nums[l_index]):
                            l_index += 1
                        r_index -= 1
                        while (l_index<r_index and nums[r_index+1]==nums[r_index]):
                            r_index -= 1
        
        return fS_ans
