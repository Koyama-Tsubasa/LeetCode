class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // parameters
        std::vector<int> InDegree(n, 0), OutDegree(n, 0);

        // start computing
        if (trust.size() >= n-1) {

            for (auto &relationship: trust) {

                InDegree[relationship[1]-1]++;
                OutDegree[relationship[0]-1]++;

            }
            for (int i=0; i<n; i++) 
                if ((InDegree[i] == n-1) && (OutDegree[i] == 0)) 
                    return i+1;

        }

        return -1;

    }
};
