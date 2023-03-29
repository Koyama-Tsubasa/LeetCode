class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """

        # parameters
        sorted_string = ""
        char_num_mapping = {}
        frequency = []

        # start computing
        # calculate the number of each characters
        for c in s:
            char_num_mapping[c] = char_num_mapping.get(c, 0) + 1
        
        # create the MAX_Heap from the mapping result
        for c,n in char_num_mapping.items():
            heapq.heappush(frequency, [(-1)*n, c])
        
        # create sorted string
        while frequency:
            [curr_n, curr_c] = heapq.heappop(frequency)
            sorted_string += curr_c*((-1)*curr_n)
        
        return sorted_string
