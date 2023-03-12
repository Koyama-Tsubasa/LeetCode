class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        # check if the subIP is valid
        def check_valid(check_IP):
            if (len(check_IP) == 1):
                return True
            elif (check_IP[0] == '0'):
                return False
            else:
                return (int(check_IP) <= 255)
        

        # parameters
        s_length = len(s)
        first, second, third, forth = "", "", "", ""
        possibleIP = []

        # start computing
        if (s_length > 12):
            return []
        for len1 in range(1, 4):
            for len2 in range(1, 4):
                for len3 in range(1, 4):
                    if (((len1+len2+len3) < s_length) and
                        (s_length <= (len1+len2+len3+3))):
                        first = s[0:len1]
                        second = s[len1:len1+len2]
                        third = s[len1+len2:len1+len2+len3]
                        forth = s[len1+len2+len3:]
                        if (check_valid(first) and check_valid(second) and
                            check_valid(third) and check_valid(forth)):
                            possibleIP.append(first+"."+second+"."+third+"."+forth)

