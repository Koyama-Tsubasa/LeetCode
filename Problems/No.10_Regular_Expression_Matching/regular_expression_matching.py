class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        
        # check if the remain strings are valid
        def check_valid(s_index, p_index):
            
            # check for each case
            if (s_index<0 and p_index<0):
                return True
            elif (p_index<0 and s_index>=0):
                return False
            elif (s_index<0 and p_index>=0):
                if (p_index%2 == 0):
                    return False
                else:
                    for k in range(1, p_index+1, 2):
                        if (p[k] != '*'):
                            return False
                    return True
            else:
                
                # check if it is '*'
                if (p[p_index] != '*'):
                    if (p[p_index]=='.' or p[p_index]==s[s_index]):
                        return check_valid(s_index-1, p_index-1)
                else:
                    
                    # check for each remaining case and find the valid one
                    p_index -= 1
                    for len in range(0, s_index+2):
                        if (len == 0):
                            if (check_valid(s_index-len, p_index-1)):
                                return True
                        elif (p[p_index]=='.' or s[s_index-len+1]==p[p_index]):
                            if (check_valid(s_index-len, p_index-1)):
                                return True
                        else:
                            return False
            
            return False
        
        return check_valid(len(s)-1, len(p)-1)
        
