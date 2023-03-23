class Solution(object):
    def minimumJumps(self, forbidden, a, b, x):
        """
        :type forbidden: List[int]
        :type a: int
        :type b: int
        :type x: int
        :rtype: int
        """

        # parameters
        jumps = -1
        possibleJumps = []

        # start computing
        possibleJumps.append([0, True])
        while possibleJumps:
            jumps += 1
            pP_size = len(possibleJumps)

            for i in range(pP_size):
                [currP, backC] = possibleJumps.pop(0)

                if (currP == x):
                    return jumps
                elif (currP in forbidden):
                    continue
                else:
                    
                    # backward (check if it backwarded once, also for the negative position)
                    if (backC and (0 <= currP-b)):
                        possibleJumps.append([currP-b, False])
                    
                    # forward (check if it is going to jump redundandly)
                    if (currP-b <= 2000):
                        possibleJumps.append([currP+a, True])
                
                forbidden.append(currP)

        return -1
