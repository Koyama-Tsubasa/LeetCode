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
        ExtraEnergy = (-1)*initialEnergy
        ExtraExp, ExpGap = 0, 0

        # start computing
        for id in range(len(energy)):
            # compute energy
            ExtraEnergy += energy[id]
            # compute experience
            if (experience[id] >= initialExperience):
                ExpGap = experience[id] - initialExperience + 1
                ExtraExp += ExpGap
                initialExperience += experience[id] + ExpGap
            else:
                initialExperience += experience[id]
        
        return (max((ExtraEnergy + 1), 0) + ExtraExp)
