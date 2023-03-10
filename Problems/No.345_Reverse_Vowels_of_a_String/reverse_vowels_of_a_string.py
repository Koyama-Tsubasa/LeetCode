class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """

        # parameters
        pLeft, pRight = 0, len(s)-1
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        s_list = list(s)

        # start computing
        while (True):
            while ((pLeft < pRight) and (s_list[pLeft] not in vowels)):
                pLeft += 1
            while ((pLeft < pRight) and (s_list[pRight] not in vowels)):
                pRight -= 1
            if (pLeft < pRight):
                s_list[pLeft], s_list[pRight] = s_list[pRight], s_list[pLeft]
                pLeft += 1
                pRight -= 1
            else:
                break
        
        return ''.join(s_list)
