class Solution(object):
    def minimizeResult(self, expression):
        """
        :type expression: str
        :rtype: str
        """

        # parameters
        min_value = float('inf')
        plus_idx = expression.find('+')
        min_value_string = ""

        # start computing
        for left in range(plus_idx):
            for right in range(plus_idx+1, len(expression)):
                V1 = expression[:left]
                V2 = expression[left:plus_idx]
                V3 = expression[plus_idx+1:right+1]
                V4 = expression[right+1:]

                temp_value = (1 if not V1 else int(V1)) * (int(V2) + int(V3)) * (1 if not V4 else int(V4))
                if (temp_value < min_value):
                    min_value = temp_value
                    min_value_string = V1 + "(" + V2 + "+" + V3 + ")" + V4
        
        return min_value_string
