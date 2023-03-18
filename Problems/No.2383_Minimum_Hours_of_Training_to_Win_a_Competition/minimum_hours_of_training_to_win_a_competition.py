class Solution(object):
    def minNumberOfHours(self, initialEnergy, initialExperience, energy, experience):
        """
        :type initialEnergy: int
        :type initialExperience: int
        :type energy: List[int]
        :type experience: List[int]
        :rtype: int
        """

        # parameters
        EnergySum = 0
        ExtraExp, ExpGap = 0, 0

        # start computing
        for id in range(len(energy)):
            # compute energy
            EnergySum += energy[id]
            # compute experience
            if (experience[id] >= initialExperience):
                ExpGap = experience[id] - initialExperience + 1
                ExtraExp += ExpGap
                initialExperience += experience[id] + ExpGap
            else:
                initialExperience += experience[id]
        
        return (max((EnergySum - initialEnergy + 1), 0) + ExtraExp)
