class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // parameters
        int alphaTable[26] = {0};

        // start computing
        if (s.length() != t.length()) return false;

        for (int i=0; i<s.length(); i++) {

            alphaTable[s[i]-'a']++;
            alphaTable[t[i]-'a']--;

        }

        for (int i=0; i<26; i++) if (alphaTable[i] != 0) return false;
        return true;

    }
};
