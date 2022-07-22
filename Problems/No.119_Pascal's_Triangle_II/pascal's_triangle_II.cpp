class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        // parameter
        vector<int> ans = {1};
        
        // start compute
        for (int i=0; i<rowIndex; i++) {

            ans.push_back(1);
            for (int j=i; j>0; j--) ans[j] += ans[j-1];
            
        }
        
        return ans;
        
    }
};
