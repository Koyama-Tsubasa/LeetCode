class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        # create combinations
        def create_combinations(start):
            if (len(combination) == k):
                comb = combination[:]
                combinations.append(comb)
            else:
                for i in range(start, n+1):
                    combination.append(i)
                    create_combinations(i+1)
                    combination.pop()

        # parameters
        combinations, combination = [], []

        # start computing
        create_combinations(1)
        
        return combinations
