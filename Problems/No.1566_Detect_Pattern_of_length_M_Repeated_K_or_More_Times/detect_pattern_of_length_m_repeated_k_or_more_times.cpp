class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        
        // parameter
        int pattern_cnt = 0;

        // start computing
        if (arr.size() < m*k) return false;
        for (int i=0; i<arr.size()-m; i++) {

            if (arr[i] == arr[i+m]) pattern_cnt++;
            else pattern_cnt = 0;

            if (pattern_cnt == m*(k-1)) return true;

        }

        return false;

    }
};
