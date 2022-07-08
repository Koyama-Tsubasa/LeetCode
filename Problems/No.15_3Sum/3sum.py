class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        # store the pointers
        zero, L_index, R_index = None, None, None
        threesum_ans = []
        
        # preprocess
        if (len(nums) < 3):
            return threesum_ans
        
        # start compute
        nums.sort()
        for i in range(len(nums)-2):
            
            # check if it violates the rules
            if (nums[i] > 0):
                break
            elif (i == 0 or (i > 0 and (nums[i] != nums[i-1]))):
                
                zero = -nums[i]
                L_index = i + 1
                R_index = len(nums) - 1
                
                while (L_index < R_index):
                    if (nums[L_index] + nums[R_index] < zero):
                        L_index += 1
                    elif (nums[L_index] + nums[R_index] > zero):
                        R_index -= 1
                    else:
                        threesum_ans.append([nums[i], nums[L_index], nums[R_index]])
                        while (L_index < R_index and (nums[L_index] == nums[L_index+1])):
                            L_index += 1
                        while (L_index < R_index and (nums[R_index-1] == nums[R_index])):
                            R_index -= 1
                        L_index += 1
                        R_index -= 1
                    
        return threesum_ans
