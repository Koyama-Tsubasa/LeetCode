class Solution {
public:

    // check if it is a vowel
    bool isVowel(char &c) {

        if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ||
            (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')) return true;
        else return false;

    }

    string reverseVowels(string s) {
        
        // parameters
        int pLeft = 0, pRight = s.length()-1;

        // start computing
        while (true) {

            while ((pLeft < pRight) && !isVowel(s[pLeft])) pLeft++;
            while ((pLeft < pRight) && !isVowel(s[pRight])) pRight--;

            if (pLeft < pRight) std::swap(s[pLeft++], s[pRight--]);
            else break;

        }

        return s;

    }
};
