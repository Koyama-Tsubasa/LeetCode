class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """

        # parameters
        ranges = []
        temp = ""
        i, Range = 0, None

        # start computing
        while (i < len(nums)):
            
            temp = str(nums[i])
            Range = 1
            while (Range < len(nums)-i):
                if (nums[i+Range] != nums[i]+Range):
                    break
                Range += 1

            if (Range == 1):
                ranges.append(temp)
            else:
                temp += ("->"+str(nums[i+Range-1]))
                ranges.append(temp)
                i += (Range-1)
            i += 1

        return ranges
