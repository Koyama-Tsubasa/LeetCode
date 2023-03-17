class Solution {
public:
    int maximum69Number (int num) {
        
        // parameter
        int num_length = std::to_string(num).length();

        // start computing
        for (int n=num, div=std::pow(10, num_length-1); div>0; n%=div, div/=10) 
            if ((n/div) == 6) return (num + 3*div);

        return num;

    }
};
