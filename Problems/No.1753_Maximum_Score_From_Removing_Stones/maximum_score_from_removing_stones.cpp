class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        // parameters
        std::priority_queue<int> StoneAmounts;
        int moves = 0;

        // start computing
        StoneAmounts.push(a);
        StoneAmounts.push(b);
        StoneAmounts.push(c);
        while (!StoneAmounts.empty()) {

            auto stone1 = StoneAmounts.top();
            StoneAmounts.pop();
            auto stone2 = StoneAmounts.top();
            StoneAmounts.pop();

            if ((stone1 == 0) || (stone2 == 0)) break;
            else {

                moves++;
                StoneAmounts.push(stone1-1);
                StoneAmounts.push(stone2-1);

            }

        }

        return moves;

    }
};
