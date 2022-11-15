class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # parameters
        happy_or_not = False
        n_str = ""
        temp = 0

        # start compute
        while (not happy_or_not):

            # first convert into integer and reset the number
            n_str = str(n)
            n = 0

            # calculate
            for c in n_str:
                temp = int(c)
                n += temp*temp

            # check if the number is happy or not 
            # (if encounter 4, it will start the unlimited loop)
            if (n == 1):
                happy_or_not = True
            elif (n == 4):
                break
            
        return happy_or_not
