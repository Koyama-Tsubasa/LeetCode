class Solution(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """

        # parameters
        num_of_house = len(garbage)
        total_time = 0
    
        # start computing
        for g in ['M', 'P', 'G']:
            partial_time = 0
            to_the_next_stop = 0
            for i in range(num_of_house):
                picked_g_size = garbage[i].count(g)
                to_the_next_stop = travel[i] if (i+1 < num_of_house) else -1
                if picked_g_size:
                    total_time += partial_time + picked_g_size
                    partial_time = to_the_next_stop
                else:
                    partial_time += to_the_next_stop
        
        return total_time
                
