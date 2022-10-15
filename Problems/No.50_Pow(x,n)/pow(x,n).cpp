class Solution {
public:
    
    // Pow(x, n) for n>0
    double positive_power(double x, int n) {
        
        if (n == 1) return x;
        else {
            
            if (n%2 == 0) return positive_power(x*x, n/2);
            else return x*positive_power(x, n-1);
            
        }
        
    }
    
    // Pow(x, n) for n<0
    double negative_power(double x, int n) {
        
        if (n == -1) return x;
        else {
            
            if (n%2 == 0) return negative_power(x*x, n/2);
            else return x*negative_power(x, n+1);
            
        }
        
    }
    
    double myPow(double x, int n) {
        
        if (n == 0) return 1.0;
        else {
            
            if (n > 0) return positive_power(x, n);
            else return negative_power(1/x, n);
            
        }
        
    }
};
