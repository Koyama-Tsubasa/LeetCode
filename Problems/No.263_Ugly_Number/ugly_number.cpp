class Solution {
public:
    bool isUgly(int n) {
        
        // start computing
        if (n <= 0) return false;
        for (int div: {2, 3, 5}) while (n%div == 0) n /= div;

        return (n == 1);

    }
};
