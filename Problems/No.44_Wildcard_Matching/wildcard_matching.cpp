class Solution {
public:
    bool isMatch(string s, string p) {
        
        // parameters
        int sID, pID;
        bool flag;
        int s_length = s.length();
        int p_length = p.length();
        std::vector<std::vector<bool>> matching(p_length+1, std::vector<bool>(s_length+1, false));

        // start computing (use Dynamic Proramming)
        // reference: https://reurl.cc/XL5ZV0

        // base
        matching[0][0] = true;

        // check for the case of p_length = 0
        for (sID=1; sID<=s_length; sID++) matching[0][sID] = false;

        // check for the case of s_length = 0
        flag = true;
        for (pID=1; pID<=p_length; pID++) {

            flag &= (p[pID-1] == '*');
            matching[pID][0] = flag;

        }

        // start matching
        for (pID=1; pID<=p_length; pID++) {
            for (sID=1; sID<=s_length; sID++) {

                if ((p[pID-1] == s[sID-1]) || (p[pID-1] == '?')) matching[pID][sID] = matching[pID-1][sID-1];
                else if (p[pID-1] == '*') matching[pID][sID] = matching[pID-1][sID] || matching[pID][sID-1];
                else matching[pID][sID] = false;

            }
        }

        return matching[p_length][s_length];

    }
};
