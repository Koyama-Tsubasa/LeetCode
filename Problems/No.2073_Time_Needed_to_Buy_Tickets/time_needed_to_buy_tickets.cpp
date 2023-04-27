class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        // parameters
        int time_for_k = tickets[k];
        int time = 0;

        // start computing
        for (int i=0; i<tickets.size(); i++) {

            time += std::min(tickets[i], time_for_k);
            if (i == k) time_for_k--;

        }

        return time;

    }
};
