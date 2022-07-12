class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        
        # parameters
        check_negative = (dividend>=0)^(divisor>=0)
        DTI_ans = 0
        
        # edge cases
        if (dividend == 0):
            return 0
        elif (divisor == 1):
            return dividend
        elif (dividend==-2147483648 and divisor==-1):
            return 2147483647
        else:
            
            # change them into negative since we have to deal with -2^31
            # we can not deal with 2^31 since the environment can only store 32-bit
            if (dividend > 0):
                dividend = -dividend
            if (divisor > 0):
                divisor = -divisor
            
            '''
            
            start compute, use the technique below
            
            ex1 (-15/-3):
                -15 = -12 + (-3) 
                    = 4*(-3) + (-3) 
                    = (2^2)*(-3) + (-3) 
                    = (2^2 + 1)*(-3) + 0
                    = 5*(-3) + 0
                    
            ex2 (-23/-3): 
                -23 = -12 + (-6) + (-3) + (-2)
                    = 4*(-3) + 2*(-3) + (-3) + (-2)
                    = (2^2)*(-3) + (2^1)*(-3) + (-3) + (-2)
                    = (2^2 + 2^1 + 1)*(-3) + (-2)
                    = 7*(-3) + (-2)
                    
            '''
            while (divisor >= dividend):
                
                temp = divisor
                temp_ans = 1
                
                '''
                
                use the technique below to avoid the overflow, 
                you can try dividend = -2147483648, divisor = -3 without the following while loop
                
                ex (-15/-3):
                    
                    loop 1: dividend = -15, DTI_ans = 0, temp_ans = 1
                    
                        temp = -3  >= -12 = dividend-temp, temp_ans = 2
                        temp = -6  >= -9  = dividend-temp, temp_ans = 4
                        temp = -12 <  -4  = dividend-temp, break
                        
                        dividend = -15 - (-12) = -3
                        DTI_ans = 0 + temp_ans = 4
                        
                    loop 2: dividend = -3, DTI_ans = 4, temp_ans = 1
                    
                        temp = -3 < 0 = dividend-temp, break
                        
                        dividend = -3 - (-3) = 0
                        DTI_ans = 4 + temp_ans = 5
                        
                    loop 3: divisor = -3 < 0 = dividend, break
                
                '''
                
                while (temp >= dividend-temp):
                    
                    temp += temp
                    temp_ans += temp_ans
                
                dividend -= temp
                DTI_ans += temp_ans
            
        return -DTI_ans if check_negative else DTI_ans
