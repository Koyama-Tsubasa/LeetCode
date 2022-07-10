class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        
        # store some parameters
        GP_ans = []
        stack = []
        stack.append(("", 0, 0))
        
        # DFS (backtracking) method with iterative
        while stack:
            s, opened, closed = stack.pop()
            
            # check if the length of s is valid
            if (len(s) == 2*n):
                GP_ans.append(s)
            else:
                
                # if the open branket is less than n then new branch
                if (opened < n):
                    stack.append((s+"(", opened+1, closed))
                
                # if the close branket is less than open branket then new branch
                if (closed < opened):
                    stack.append((s+")", opened, closed+1))
        
        return GP_ans
