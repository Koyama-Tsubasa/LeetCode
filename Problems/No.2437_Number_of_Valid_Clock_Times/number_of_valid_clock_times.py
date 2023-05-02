class Solution(object):
    def countTime(self, time):
        """
        :type time: str
        :rtype: int
        """

        # parameter
        valid_cnt = 1
    
        # start computing
        if (time[0] == '?'):
            if (time[1] == '?'):
                valid_cnt *= 24
            elif ('0' <= time[1] <= '3'):
                valid_cnt *= 3
            else:
                valid_cnt *= 2
        elif (time[1] == '?'):
            if (time[0] == '2'):
                valid_cnt *= 4
            else:
                valid_cnt *= 10
        
        if (time[3] == '?'):
            valid_cnt *= 6
        if (time[4] == '?'):
            valid_cnt *= 10
        
        return valid_cnt
