class Solution {
public:

    // palindrome chance of deleting one character
    bool PalindromeChance(std::string s, int L, int R) {

        while (L < R) {

            if (s[L] == s[R]) {

                L++;
                R--;

            }
            else return false;

        }

        return true;

    }

    bool validPalindrome(string s) {
        
        // parameters
        int pLeft = 0, pRight = s.length()-1;

        // start computing
        while (pLeft < pRight) {

            if (s[pLeft] == s[pRight]) {

                pLeft++;
                pRight--;

            }
            else return (PalindromeChance(s, pLeft+1, pRight) || PalindromeChance(s, pLeft, pRight-1));
        }

        return true;

    }
};
