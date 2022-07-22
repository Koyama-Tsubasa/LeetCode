class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // parameter
        vector<vector<int>> ans;
        
        // start compute
        for (int i=0; i<numRows; i++) {
            
            ans.push_back({});

            for (int j=0; j<i; j++) {

                if (j == 0) ans[i].push_back(1);
                else ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);

            }
            
            ans[i].push_back(1);
            
        }   

        return ans;
        
    }
};
