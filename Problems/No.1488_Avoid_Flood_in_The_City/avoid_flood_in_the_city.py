class Solution(object):
    def avoidFlood(self, rains):
        """
        :type rains: List[int]
        :rtype: List[int]
        """

        # reference: 
        # https://leetcode.com/problems/avoid-flood-in-the-city/solutions/697950/python-well-explained-simple-logic-o-nlogn-greedy-and-heap/

        # parameters
        rainy_days = collections.defaultdict(list)
        Date_of_Flood = []
        flood_avoidance = []

        # start computing
        # calculate the rainy days over the nth lake
        for day, lake in enumerate(rains):
            if lake:
                rainy_days[lake].append(day)

        # start rain & dry
        for i in range(len(rains)):
            lake = rains[i]
            if lake:
                flood_avoidance.append(-1)
                if rainy_days[lake]:
                    # check if it will flood
                    if (rainy_days[lake][0] < i):
                        return []
                    elif (len(rainy_days[lake]) > 1):
                        heapq.heappush(Date_of_Flood, rainy_days[lake][1])
                                               
            else:
                # check if there is a lake to dry
                if not Date_of_Flood:
                    flood_avoidance.append(1)
                else:
                    flood_avoidance.append(rains[heapq.heappop(Date_of_Flood)])
                    rainy_days[flood_avoidance[i]].pop(0)

        return flood_avoidance
