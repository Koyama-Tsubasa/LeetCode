class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        // reference: 
        // https://leetcode.com/problems/avoid-flood-in-the-city/solutions/2723925/c-pointer-array-with-min-heap-that-beats-99-81-in-time-and-95-25-in-space/

        // parameters
        std::unordered_map<int, int> last_rainy_day;
        std::vector<int> next_rainy_day(rains.size(), -1);
        std::priority_queue<int, std::vector<int>, std::greater<int>> Date_of_Flood;
        std::vector<int> flood_avoidance;

        // start computing
        // calculate the next rainy day over the nth lake
        for (int i=0; i<rains.size(); i++) {
            if (rains[i]) {

                if (last_rainy_day.find(rains[i]) != last_rainy_day.end()) 
                    next_rainy_day[last_rainy_day[rains[i]]] = i;
                last_rainy_day[rains[i]] = i;

            }
        }

        // start to rain & dry
        for (int i=0; i<rains.size(); i++) {

            if (rains[i]) {

                if (!Date_of_Flood.empty() && Date_of_Flood.top() <= i) return {};
                else if (next_rainy_day[i] != -1) Date_of_Flood.push(next_rainy_day[i]);
                flood_avoidance.push_back(-1);

            }
            else {

                if (Date_of_Flood.empty()) flood_avoidance.push_back(1);
                else {

                    flood_avoidance.push_back(rains[Date_of_Flood.top()]);
                    Date_of_Flood.pop();

                }

            }

        }

        return flood_avoidance;

    }
};
