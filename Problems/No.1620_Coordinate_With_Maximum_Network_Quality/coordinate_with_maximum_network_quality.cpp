class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        
        // parameters
        int MAX_x = 0, min_x = INT_MAX;
        int MAX_y = 0, min_y = INT_MAX;
        int MAX_quality = 0;
        std::vector<int> highest_quality = {0, 0};

        // start computing
        // calculate the edge points of the bounding box
        for (auto &coordinate: towers) {

            int tower_x = coordinate[0], tower_y = coordinate[1];
            MAX_x = std::max(MAX_x, tower_x);
            MAX_y = std::max(MAX_y, tower_y);
            min_x = std::min(min_x, tower_x);
            min_y = std::min(min_y, tower_y);

        }

        // find the highest quality from the inside of the bounding box
        for (int x=min_x; x<=MAX_x; x++) 
            for (int y=min_y; y<=MAX_y; y++) {

                int curr_quality = 0;
                for (auto &tower: towers) {

                    float distance = std::sqrt(std::pow(x-tower[0], 2) + std::pow(y-tower[1], 2));
                    if (distance > radius) continue;
                    curr_quality += (tower[2]/(1 + distance));

                }
                if (curr_quality > MAX_quality) {

                    MAX_quality = curr_quality;
                    highest_quality = {x, y};

                }

            }

        return highest_quality;

    }
};
