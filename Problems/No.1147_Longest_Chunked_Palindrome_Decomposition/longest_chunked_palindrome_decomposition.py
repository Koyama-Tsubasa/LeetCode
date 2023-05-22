class Solution(object):
    def longestDecomposition(self, text):
        """
        :type text: str
        :rtype: int
        """

        # parameters
        left_idx, right_idx = 0, len(text)
        sub_length = 0
        subtext_cnt = 0
    
        # start computing
        while (left_idx <= right_idx):
            sub_length += 1
            if (text[left_idx:left_idx+sub_length] == text[right_idx-sub_length:right_idx]):
                left_idx += sub_length
                right_idx -= sub_length
                sub_length = 0

                if (left_idx < right_idx):
                    subtext_cnt += 2
                else:
                    subtext_cnt += 1
        
        return subtext_cnt
