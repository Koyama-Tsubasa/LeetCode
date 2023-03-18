class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        // parameters
        int ExtraEnergy = (-1)*initialEnergy;
        int ExtraExp = 0, ExpGap;

        // start computing
        for (int id=0; id<energy.size(); id++) {

            // compute energy
            ExtraEnergy += energy[id];

            // compute experience
            if (experience[id] >= initialExperience) {

                ExpGap = experience[id] - initialExperience + 1;
                ExtraExp += ExpGap;
                initialExperience += experience[id] + ExpGap;

            }
            else initialExperience += experience[id];

        }

        return (std::max((ExtraEnergy + 1), 0) + ExtraExp);

    }
};
