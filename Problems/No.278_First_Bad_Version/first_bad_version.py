# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """

        # parameters
        early, late, mid = 1, n, None
        latest = None

        # start computing
        while (early <= late):
            mid = (early+late)//2
            if isBadVersion(mid):
                late = mid - 1
                latest = mid
            else:
                early = mid + 1
        
        return latest
