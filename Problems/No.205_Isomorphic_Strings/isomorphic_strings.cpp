class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // parameters
        std::unordered_map<char, char> check_st, check_ts;

        // start computing
        if (s.length() != t.length()) return false;
        else {

            for (int i=0; i<s.length(); i++) {
                
                if (check_st[s[i]] && (check_st[s[i]] != t[i])) return false;
                if (check_ts[t[i]] && (check_ts[t[i]] != s[i])) return false;
                check_st[s[i]] = t[i];
                check_ts[t[i]] = s[i];

            }

        }

        return true;

    }
};
