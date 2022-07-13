class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // parameters
        int m_ = m - 1, n_ = n - 1;
        
        // start compute
        for (int ans=nums1.size()-1; ans>=0; ans--) {
            
            if (n_ == -1) break;
            else if (m_>=0 and nums1[m_] > nums2[n_]) nums1[ans] = nums1[m_--];
            else nums1[ans] = nums2[n_--];
            
        }
        
    }
};
