class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        // parameters
        int jumps = -1;
        std::unordered_set<int> forbiddenPositions(forbidden.begin(), forbidden.end());
        std::queue<std::pair<int, bool>> possiblePositions;

        // start computing
        possiblePositions.push({0, true});
        while (!possiblePositions.empty()) {

            jumps++;
            auto pP_size = possiblePositions.size();

            for (int i=0; i<pP_size; i++) {

                auto [currP, backC] = possiblePositions.front();
                possiblePositions.pop();

                if (currP == x) return jumps;
                else if (forbiddenPositions.find(currP) != forbiddenPositions.end()) continue;
                else {

                    // backward (check if it backwarded once, also for the negative position)
                    if (backC && (0 <= currP-b)) possiblePositions.push({currP-b, false});

                    // forward (check if it is going to jump redundandly)
                    if (currP-b <= 2000) possiblePositions.push({currP+a, true});

                }

                forbiddenPositions.insert(currP);
            
            }

        }

        return -1;

    }
};
