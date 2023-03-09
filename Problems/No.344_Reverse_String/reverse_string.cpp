class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // parameters
        int left = 0, right = s.size()-1;

        // start computing
        while (left < right) std::swap(s[left++], s[right--]);

    }
};
