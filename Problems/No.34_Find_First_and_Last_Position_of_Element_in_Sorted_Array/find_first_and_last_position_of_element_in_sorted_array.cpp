class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // parameters
        int left, right, mid;
        int start = -1, end = -1;
        vector<int> ans;
        
        // start compute, using binary search method
        // find starting index
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            
            mid = (left+right)/2;
            
            if (nums[mid] == target) {
                
                start = mid;
                right = mid - 1;
                
            }
            else if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
            
        }
        
        // find ending index
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            
            mid = (left+right)/2;
            
            if (nums[mid] == target) {
                
                end = mid;
                left = mid + 1;
                
            }
            else if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
            
        }
        
        ans.push_back(start);
        ans.push_back(end);
        return ans;
        
    }
};
