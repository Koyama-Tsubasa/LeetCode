class Solution {
public:
    bool isHappy(int n) {
        
        // parameters
        bool happy_or_not = false;
        string n_str;
        int temp;

        // start compute
        while (!happy_or_not) {
            
            // first convert into integer and reset the number
            n_str = to_string(n);
            n = 0;

            // calculate
            for (auto c:n_str) {

                temp = int(c) - 48;
                n += temp*temp;
                
            }
            
            // check if the number is happy or not 
            // (if encounter 4, it will start the unlimited loop)
            if (n == 1) happy_or_not = true;
            else if (n == 4) break;

        }

        return happy_or_not;

    }
};
