class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        
        // parameters
        int partial_start = 0;
        int max_win_2segs = 0;
        std::vector<int> max_wins(prizePositions.size()+1, 0);

        // start computing
        for (int i=0; i<prizePositions.size(); i++) {
            
            // find the partial start point of the current subarray to index i
            while (prizePositions[i] > prizePositions[partial_start]+k)
                partial_start++;
            
            // calculate the maximum wins at the current position
            max_wins[i+1] = std::max(max_wins[i], i-partial_start+1);

            // find the maximum wins with two segments at the current position
            max_win_2segs = std::max(max_win_2segs, i-partial_start+1 + max_wins[partial_start]);
            
        }

        return max_win_2segs;

    }
};
