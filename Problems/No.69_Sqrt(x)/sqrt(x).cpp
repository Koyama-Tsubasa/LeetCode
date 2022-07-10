class Solution {
public:
    int mySqrt(int x) {
        
        // store some parameters
        int left = 0;
        int right = x;
        long mid;
        long Sqrt_ans;
        long temp;
        
        // start compute (BinarySearch method)
        while (left <= right) {
            
            mid = (left+right)/2;
            temp = mid*mid;
            
            if (temp == x) return mid;
            else if (temp > x) right = mid - 1;
            else {
                
                left = mid + 1;
                Sqrt_ans = mid;
                
            }
            
        }
        
        return Sqrt_ans;
        
    }
};
