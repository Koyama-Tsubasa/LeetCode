class Solution {
public:
    int climbStairs(int n) {
        
        // dynamic programming
        // T(n) = T(n-1) + T(n-2)
        // T(1) = 1, T(2) = 2, T(3) = 3
        
        // store T(n-1) and T(n-2)
        int T_1, T_2;
        int temp;
        
        // start compute
        if (n < 4) return n;
        else {
            
            // initialize T(n-1) = T(3), T(n-2) = T(2)
            T_1 = 3;
            T_2 = 2;
            
            // iterate
            for (int i=0; i<n-4; i++) {
                
                temp = T_1;
                T_1 += T_2;
                T_2 = temp;
                
            }
            
        }
        
        return T_1+T_2;
        
    }
};
