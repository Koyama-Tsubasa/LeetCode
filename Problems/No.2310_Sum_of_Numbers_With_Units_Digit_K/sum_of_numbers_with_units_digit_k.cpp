class Solution {
public:
    int minimumNumbers(int num, int k) {
        
        // start computing
        if (num == 0) return 0;
        else {

            for (int minSize=1; minSize<=10; minSize++) 
                if (((minSize*k % 10) == (num % 10)) && (minSize*k <= num))
                    return minSize;
            
            return -1;

        }

    }
};
