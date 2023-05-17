class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        // parameter
        std::set<std::string> k_binary_codes;
        int all_codes = 1<<k;

        // start computing
        if (s.length() < k+all_codes-1) return false;
        for (int i=0; i<=s.length()-k; i++)
            k_binary_codes.insert(s.substr(i, k));
        
        return (k_binary_codes.size() == all_codes) ? true : false;

    }
};
