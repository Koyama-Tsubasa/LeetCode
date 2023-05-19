class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        // parameters
        int MAX_length = 0;
        int n1_size = nums1.size();
        int n2_size = nums2.size();
        std::vector<std::vector<int>> DP(n1_size+1, std::vector<int>(n2_size+1, 0));

        // start computing
        for (int i=1; i<=n1_size; i++)
            for (int j=1; j<=n2_size; j++) {

                if (nums1[i-1] == nums2[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
                else DP[i][j] = 0;
                MAX_length = std::max(MAX_length, DP[i][j]);

            }

        return MAX_length;

    }
};
