class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """

        # parameters
        Radiants, Dires = [], []
        senate_size = len(senate)

        # start computing
        for i, c in enumerate(senate):
            if (c == 'R'):
                Radiants.append(i)
            else:
                Dires.append(i)

        while (Radiants and Dires):
            curr_R = Radiants.pop(0)
            curr_D = Dires.pop(0)

            if (curr_R < curr_D):
                Radiants.append(senate_size + curr_R)
            else:
                Dires.append(senate_size + curr_D)

        return "Radiant" if Radiants else "Dire"
