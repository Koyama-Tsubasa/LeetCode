class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // store the answer and the pointers
        int CWMW_ans = 0;
        int local_ans;
        int left = 0;
        int right = height.size() - 1;
        
        
        // start compute
        while (left < right) {
            
            local_ans = right - left;
            
            // case by case
            if (height[left] < height[right]) {
                
                local_ans *= height[left];
                left++;
                
            }
            else if (height[left] > height[right]) {
                
                local_ans *= height[right];
                right--;
                
            }
            else {
                
                local_ans *= height[left];
                left++;
                right--;
                
            }
            
            CWMW_ans = (local_ans>CWMW_ans) ? local_ans : CWMW_ans;
            
        }
        
        return CWMW_ans;
        
    }
};
