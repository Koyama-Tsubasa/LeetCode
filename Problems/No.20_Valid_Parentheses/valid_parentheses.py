class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        # prepare the stack and the valid patterns
        stack = [] 
        check = {"(":")", "{":"}", "[":"]"}
        
        # start compute
        for element in s:
            
            # decide to push in or pop out
            if (element in "({["):
                stack.append(element)
            else:
                
                # check whether the stack is empty, pattern correctness or not
                if (stack == []):
                    return False
                elif (element != check[stack[-1]]):
                    return False
                else:
                    stack.pop()
            
        return stack == []
