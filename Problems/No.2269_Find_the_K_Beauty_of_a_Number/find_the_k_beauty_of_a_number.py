class Solution(object):
    def divisorSubstrings(self, num, k):
        """
        :type num: int
        :type k: int
        :rtype: int
        """

        # parameters
        k_beauty = 0
        numString = str(num)

        # start computing
        for i in range(len(numString)-k+1):
            sub_num = int(numString[i:i+k])
            if (sub_num != 0):
                if (num%sub_num == 0):
                    k_beauty += 1

        return k_beauty
