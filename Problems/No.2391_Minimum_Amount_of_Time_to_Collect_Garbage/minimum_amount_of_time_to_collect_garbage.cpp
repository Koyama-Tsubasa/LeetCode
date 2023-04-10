class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        // parameters
        int num_of_house = garbage.size();
        int total_time = 0;

        // start computing
        for (auto g: {'M', 'P', 'G'}) {

            int partial_time = 0;
            int to_the_next_stop = 0;
            for (int i=0; i<num_of_house; i++) {

                int picked_g_size = std::count(garbage[i].begin(), garbage[i].end(), g);
                if (i+1 < num_of_house) to_the_next_stop = travel[i];
                if (picked_g_size > 0) {

                    total_time += partial_time + picked_g_size;
                    partial_time = to_the_next_stop;

                }
                else partial_time += to_the_next_stop;

            }

        }

        return total_time;

    }
};
