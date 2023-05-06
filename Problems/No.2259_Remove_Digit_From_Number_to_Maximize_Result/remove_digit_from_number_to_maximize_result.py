class Solution(object):
    def removeDigit(self, number, digit):
        """
        :type number: str
        :type digit: str
        :rtype: str
        """

        # parameters
        removed_MAX = ""
        num_len = len(number)

        # start computing
        for i, c in enumerate(number):
            if (c == digit):
                temp_num = number[:i]
                if (i < num_len-1):
                    temp_num += number[i+1:]
                removed_MAX = max(removed_MAX, temp_num)
        
        return removed_MAX
