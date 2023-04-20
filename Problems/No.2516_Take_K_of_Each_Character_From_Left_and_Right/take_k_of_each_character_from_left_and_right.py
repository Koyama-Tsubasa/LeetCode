class Solution(object):
    def takeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """

        # parameters
        minutes = float('inf')
        char_map = {'a': 0, 'b': 0, 'c': 0}

        # start computing
        # calculate the total number of each character and check for the constraint
        for c in s:
            char_map[c] += 1
        if ((char_map['a'] < k) or (char_map['b'] < k) or (char_map['c'] < k)):
            return -1
        
        # traverse the string from left and right to find the minimum minutes
        s_len = len(s)
        left, right = 0, 0
        while (left < s_len):
            while ((right <= s_len) and
                   (char_map['a'] >= k) and (char_map['b'] >= k) and (char_map['c'] >= k)):
                if (right < s_len):
                    char_map[s[right]] -= 1
                right += 1
            minutes = min(minutes, left + (s_len-right) + 1)
            char_map[s[left]] += 1
            left += 1
    
        return minutes
