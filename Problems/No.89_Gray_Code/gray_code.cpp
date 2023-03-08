class Solution {
public:
    vector<int> grayCode(int n) {
        
        // parameters
        std::vector<int> GCode = {0, 1};
        int cNum;
        
        // start computing
        for (int i=2; i<(1<<n); i++) {
            
            cNum = i ^ (i>>1);
            GCode.push_back(cNum);

        }

        return GCode;

    }
};
