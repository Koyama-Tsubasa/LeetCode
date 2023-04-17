class Solution(object):
    def countGoodSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """

        # parameters
        count, duplicated = 0, 0
        check_count = {}
        
        # start computing
        if (len(s) < 3):
            return 0
        else:
            for i in range(len(s)):
                check_count[s[i]] = check_count.get(s[i], 0) + 1
                if (check_count[s[i]] == 2):
                    duplicated += 1
                
                if (i < 2):
                    continue
                else:
                    if not duplicated:
                        count += 1
                    check_count[s[i-2]] -= 1
                    if (check_count[s[i-2]] == 1):
                        duplicated -= 1

            return count
