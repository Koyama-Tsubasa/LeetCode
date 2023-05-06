class Solution(object):
    def bestCoordinate(self, towers, radius):
        """
        :type towers: List[List[int]]
        :type radius: int
        :rtype: List[int]
        """

        # parameters
        MAX_x, min_x = 0, float('inf')
        MAX_y, min_y = 0, float('inf')
        MAX_quality = 0
        highest_quality = [0, 0]

        # start computing
        # calculate the edgepoints of the bounding box
        for [tower_x, tower_y, _] in towers:
            MAX_x = max(MAX_x, tower_x)
            MAX_y = max(MAX_y, tower_y)
            min_x = min(min_x, tower_x)
            min_y = min(min_y, tower_y)
        
        # find the highest quality from the inside of the bounding box
        for x in range(min_x, MAX_x+1):
            for y in range(min_y, MAX_y+1):
                curr_quality = 0
                for [tower_x, tower_y, tower_quality] in towers:
                    distance = math.sqrt((x-tower_x)**2 + (y-tower_y)**2)
                    if (distance > radius):
                        continue
                    curr_quality += (tower_quality//(1 + distance))
                if (curr_quality > MAX_quality):
                    MAX_quality = curr_quality
                    highest_quality = [x, y]
        
        return highest_quality
