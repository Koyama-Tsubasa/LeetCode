class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        // parameter
        long long cnt = 0;
        int higher_cost = std::max(cost1, cost2);
        int lower_cost = std::min(cost1, cost2);

        // start computing
        int remains = total;
        for (int i=0; i<=total/higher_cost; i++) {

            cnt += (remains/lower_cost + 1);
            remains -= higher_cost;

        }

        return cnt;

    }
};
