class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """

        # start computing
        if not n:
            return True
        else:
            for i in range(len(flowerbed)):
                if (not flowerbed[i] and
                    ((i == 0) or not flowerbed[i-1]) and
                    ((i == len(flowerbed)-1) or not flowerbed[i+1])):
                    n -= 1
                    if (n == 0):
                        return True
                    flowerbed[i] = 1
            return False
