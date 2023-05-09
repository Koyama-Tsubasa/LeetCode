class RangeFreqQuery(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        self.value_mapping = {}
        for i, num in enumerate(arr):
            if num in self.value_mapping:
                self.value_mapping[num].append(i)
            else:
                self.value_mapping[num] = [i]


    def find_left(self, idxs, L_limit):
        left_edge = -1
        left, right = 0, len(idxs)-1

        while (left <= right):
            
            mid = (left + right)//2
            if (idxs[mid] < L_limit):
                left_edge = mid
                left = mid + 1
            else:
                right = mid - 1
        
        return left_edge + 1
    

    def find_right(self, idxs, R_limit):
        right_edge = len(idxs)
        left, right = 0, len(idxs)-1

        while (left <= right):
            mid = (left + right)//2
            if (R_limit < idxs[mid]):
                right_edge = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return right_edge - 1


    def query(self, left, right, value):
        """
        :type left: int
        :type right: int
        :type value: int
        :rtype: int
        """
        
        if value not in self.value_mapping:
            return 0
        
        left_ID = self.find_left(self.value_mapping[value], left)
        right_ID = self.find_right(self.value_mapping[value], right)

        return (right_ID - left_ID + 1)
        


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
