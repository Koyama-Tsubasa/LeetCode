class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """

        # parameter
        sequential_digits = []

        # start computing
        digits = "123456789"
        for i in range(len(str(low)), len(str(high))+1):
            for idx in range(9-i+1):
                temp_digit = int(digits[idx:idx+i])
                if (low <= temp_digit <= high):
                    sequential_digits.append(temp_digit)
                elif (temp_digit < low):
                    continue
                else:
                    break
        
        return sequential_digits
