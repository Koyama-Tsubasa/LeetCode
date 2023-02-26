class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        # parameters
        pLeft, pRight = 1, len(height)-2
        maxL, maxR = height[0], height[-1]
        trapped_water = 0

        # start computing
        if (len(height) <= 2):
            return 0
        while (pLeft <= pRight):
            if (maxL < maxR):
                if (height[pLeft] > maxL):
                    maxL = height[pLeft]
                else:
                    trapped_water += (maxL-height[pLeft])
                pLeft += 1
            else:
                if (height[pRight] > maxR):
                    maxR = height[pRight]
                else:
                    trapped_water += (maxR-height[pRight])
                pRight -= 1
        
        return trapped_water
