class Solution {
public:
    
    // check if the remain strings are valid
    bool check_valid(int s_index, int p_index, string& s, string& p) {
        
        // check for each case
        if (s_index<0 and p_index<0) return true;
        else if (p_index<0 and s_index>=0) return false;
        else if (s_index<0 and p_index>=0) {
                
            if (p_index%2 == 0)return false;
            else {

                for(int k=1; k<=p_index; k+=2) if (p[k] != '*') return false;
                return true;                    

            }

        }
        else {
            
            // check if it is '*'
            if (p[p_index] != '*') {
                
                // check the values are matched or the pattern is '.'
                if (p[p_index]=='.' or p[p_index]==s[s_index]) return check_valid(s_index-1, p_index-1, s, p);

            }
            else {

                // check for each remaining case and find the valid one
                p_index--;
                for (int len=0; len<=s_index+1; len++) {

                    if (p[p_index]=='.' or s[s_index-len+1]==p[p_index] or len==0) {

                        if (check_valid(s_index-len, p_index-1, s, p)) return true;

                    }
                    else return false;

                }

            }   
            
        }
        
        return false;
        
    }
    
    bool isMatch(string s, string p) {
        
        return check_valid(s.size()-1, p.size()-1, s, p);
        
    }
};
