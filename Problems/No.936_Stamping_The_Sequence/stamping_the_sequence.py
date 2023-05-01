class Solution(object):
    def movesToStamp(self, stamp, target):
        """
        :type stamp: str
        :type target: str
        :rtype: List[int]
        """

        # check if the target idx from i can be replaced by the stamp
        def Replacable(start_idx):
            for i in range(stamp_len):
                if ((target[start_idx + i] != stamp[i]) and (target[start_idx + i] != '?')):
                    return False
            return True


        # parameters
        stamp_idx = []
        stamp_len = len(stamp)
        target_len = len(target)
        replace_count = 0
        replaced = [False] * target_len
    
        # start computing
        while (replace_count < target_len):
            changed = False
            for i in range(target_len-stamp_len+1):
                if not replaced[i] and Replacable(i):
                    # replace the corresponding stamp in target to ? & count the replaced character num
                    changed = True
                    replaced[i] = True
                    for j in range(stamp_len):
                        if (target[i+j] != '?'):
                            replace_count += 1
                    target = target[:i] + ("?" * stamp_len) + target[i+stamp_len:]
                    stamp_idx.append(i)
                    if (replace_count == target_len):
                        break
            if not changed:
                return []
        
        return reversed(stamp_idx)
