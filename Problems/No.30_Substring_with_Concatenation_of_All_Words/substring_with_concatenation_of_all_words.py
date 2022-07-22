class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        
        # parameters
        wlen = len(words[0])
        wnum = len(words)
        slen = len(s)
        check, cur = {}, {}
        ans = []
        
        # used for checking if all the words appear
        for w in words:
            if check.get(w):
                check[w] += 1
            else:
                check[w] = 1
        
        # start compute
        for i in range(slen-wnum*wlen+1):
            
            # start checking
            for j in range(i, i+wnum*wlen, wlen):
                
                temp = s[j:j+wlen]
                
                # check if the substring is in the checking dictionary
                if temp in words:
                    if cur.get(temp):
                        cur[temp] += 1
                    else:
                        cur[temp] = 1
                else:
                    break
                
                # check if the number of the substring is smaller or equal to the checking dictionary
                if (cur[temp] > check[temp]):
                    break
            
            # check if the above for loop ends with no breaking
            if (cur == check):
                ans.append(i)
            cur = {}
            
        return ans
        
