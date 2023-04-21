class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        // parameters
        int min_changes;
        int num_of_w = 0;

        // start computing
        for (int i=0; i<k; i++) if (blocks[i] == 'W') num_of_w++;
        min_changes = num_of_w;
        for (int i=1; i<blocks.size()-k+1; i++) {

            if (blocks[i-1] == 'W') num_of_w--;
            if (blocks[i+k-1] == 'W') num_of_w++;
            min_changes = std::min(min_changes, num_of_w);

        }

        return min_changes;

    }
};
