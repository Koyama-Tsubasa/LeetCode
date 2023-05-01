class Solution(object):
    def movesToStamp(self, stamp, target):
        """
        :type stamp: str
        :type target: str
        :rtype: List[int]
        """

        # check if the substring is all '?'
        def AllQ(checking_str):
            for c in checking_str:
                if (c != '?'):
                    return False
            return True


        # check if the target idx from i can be replaced by the stamp
        def Replacable(temp):
            for i in range(stamp_len):
                if ((temp[i] != stamp[i]) and (temp[i] != '?')):
                    return False
            return True


        # parameters
        stamp_idx = []
        stamp_len = len(stamp)
        target_len = len(target)
        changed = True
    
        # start computing
        while changed:
            changed = False
            for i in range(target_len-stamp_len+1):
                temp_str = target[i:i+stamp_len]
                
                if AllQ(temp_str):
                    continue
                if Replacable(temp_str):
                    # replace the corresponding stamp in target to ? & count the replaced character num
                    changed = True
                    target = target[:i] + ("?" * stamp_len) + target[i+stamp_len:]
                    stamp_idx.append(i)
                
        return reversed(stamp_idx) if AllQ(target) else []
