class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        // parameters
        int jumps = -1;
        std::unordered_set<int> forbiddenPositions(forbidden.begin(), forbidden.end());
        std::queue<std::pair<int, bool>> possibleJumps;

        // start computing
        possibleJumps.push({0, true});
        while (!possibleJumps.empty()) {

            jumps++;
            auto pP_size = possibleJumps.size();

            for (int i=0; i<pP_size; i++) {

                auto [currP, backC] = possibleJumps.front();
                possibleJumps.pop();

                if (currP == x) return jumps;
                else if (forbiddenPositions.find(currP) != forbiddenPositions.end()) continue;
                else {

                    // backward (check if it backwarded once, also for the negative position)
                    if (backC && (0 <= currP-b)) possibleJumps.push({currP-b, false});

                    // forward (check if it is going to jump redundandly)
                    if (currP-b <= 2000) possibleJumps.push({currP+a, true});

                }

                forbiddenPositions.insert(currP);
            
            }

        }

        return -1;

    }
};
