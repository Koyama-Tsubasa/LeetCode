class Solution {
public:
    int pivotInteger(int n) {
        
        // parameters
        int num_sum = (1+n)*n/2;
        int check_pivot = 0;

        // start computing
        for (int i=n; i>=1; i--) {

            check_pivot += i;
            if (check_pivot == num_sum) return i;
            num_sum -= i;

        }

        return -1;

    }
};
