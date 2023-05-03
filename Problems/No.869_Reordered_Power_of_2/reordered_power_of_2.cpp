class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        // start computing
        if (n == 1) return true;

        std::string n_str = std::to_string(n);
        sort(n_str.begin(), n_str.end());

        int curr_p2 = 1;
        for (int i=1; i<32; i++) {

            curr_p2 <<= 1;
            std::string curr_p = std::to_string(curr_p2);
            sort(curr_p.begin(), curr_p.end());
            if (n_str == curr_p) return true;

        }

        return false;

    }
};
