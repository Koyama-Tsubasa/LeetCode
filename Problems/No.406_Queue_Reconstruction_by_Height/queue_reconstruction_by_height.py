class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """

        # reference:
        # https://leetcode.com/problems/queue-reconstruction-by-height/solutions/3356753/easy-c-solution-using-sorting/

        # parameter
        reconstructed_Q = []

        # start computing
        people.sort(key=lambda person: (person[0], -person[1]), reverse=True)
        for person in people:
            reconstructed_Q.insert(person[1], person)
        
        return reconstructed_Q
