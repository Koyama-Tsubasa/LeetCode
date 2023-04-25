class Solution {
public:
    string predictPartyVictory(string senate) {
        
        // parameters
        std::queue<int> Radiants, Dires;
        int senate_size = senate.length();

        // start computing
        for (int i=0; i<senate_size; i++) {

            if (senate[i] == 'R') Radiants.push(i);
            else Dires.push(i);

        }
        while (!Radiants.empty() && !Dires.empty()) {

            int curr_R = Radiants.front();
            Radiants.pop();
            int curr_D = Dires.front();
            Dires.pop();

            if (curr_R < curr_D) Radiants.push(senate_size + curr_R);
            else Dires.push(senate_size + curr_D);

        }

        return Dires.empty() ? "Radiant" : "Dire";

    }
};
