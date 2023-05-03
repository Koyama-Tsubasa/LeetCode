class Solution(object):
    def countGoodTriplets(self, arr, a, b, c):
        """
        :type arr: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """

        # parameters
        cnt = 0
        arr_size = len(arr)

        # start computing
        for i in range(arr_size-2):
            for j in range(i+1, arr_size-1):
                if (abs(arr[i]-arr[j]) <= a):
                    for k in range(j+1, arr_size):
                        if ((abs(arr[j]-arr[k]) <= b) and (abs(arr[i]-arr[k]) <= c)):
                            cnt += 1
        
        return cnt
