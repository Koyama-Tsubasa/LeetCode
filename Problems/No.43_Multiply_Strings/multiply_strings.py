class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        
        # string to integer
        def str2int(num):
            convert, m = 0, 0
            num_ = list(num)
            while num_:
                convert += (ord(num_.pop())-48)*(10**m)
                m += 1
            return convert
        
        product = str2int(num1)*str2int(num2)
        return str(product)
        
