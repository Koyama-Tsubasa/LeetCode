class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        
        // reference:
        // https://leetcode.com/problems/sell-diminishing-valued-colored-balls/solutions/1557501/python-explained-with-diagram/

        // parameters
        int total_value = 0;
        static const int mod = 1e9 + 7;
        std::priority_queue<std::pair<int, int>> Colored_balls;
        std::unordered_map<int, int> count_values;

        // start computing
        // compute the initial value of each balls
        for (auto &balls: inventory) count_values[balls]++;
        for (auto &[ball_value, count]: count_values) Colored_balls.push({ball_value, count});

        // start selling the balls
        while (orders > 0) {

            long long curr_value = Colored_balls.top().first;
            long long curr_count = Colored_balls.top().second;
            Colored_balls.pop();

            long long next_value = 0, next_count = 0;
            if (!Colored_balls.empty()) {

                next_value = Colored_balls.top().first;
                next_count = Colored_balls.top().second;
                Colored_balls.pop();

            }

            if ((curr_value-next_value)*curr_count <= orders) {

                total_value = (total_value + ((curr_value+next_value+1)*(curr_value-next_value)/2)*curr_count)%mod;
                orders -= (curr_value-next_value)*curr_count;
                Colored_balls.push({next_value, next_count+curr_count});

            }
            else {

                int complete_row_of_values = orders / curr_count;
                int remaining_row_of_values = orders % curr_count;
                
                total_value = (total_value + (2*curr_value-complete_row_of_values+1)*complete_row_of_values/2*curr_count)%mod;
                total_value = (total_value + (curr_value-complete_row_of_values)*remaining_row_of_values)%mod;
                break;

            }

        }

        return (total_value % mod);

    }
};
