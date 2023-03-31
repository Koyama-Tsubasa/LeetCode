class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """

        # parameters
        Row_Strength = []
        kWeakestRows = []

        # start computing
        # calculate soldiers in each row & order them
        for i in range(len(mat)):
            soldiers = 0
            for s in mat[i]:
                if s:
                    soldiers += 1
                else:
                    break

            heapq.heappush(Row_Strength, [soldiers, i])

        # k weakest rows
        for i in range(k):
            kWeakestRows.append(heapq.heappop(Row_Strength)[1])

        return kWeakestRows
