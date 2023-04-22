class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        // parameter
        int k_beauty = 0;
        std::string numString = std::to_string(num);

        // start computing
        for (int i=0; i<numString.length()-k+1; i++) {

            int sub_num = std::stoi(numString.substr(i, k));
            if (sub_num != 0) if (num%sub_num == 0) k_beauty++;

        }

        return k_beauty;

    }
};
