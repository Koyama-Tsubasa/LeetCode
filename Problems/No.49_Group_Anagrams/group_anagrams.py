class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        
        # parameter
        Anagrams = defaultdict(list)
        
        # start compute
        for s in strs:
            Anagrams[''.join(sorted(s))].append(s)
        
        return Anagrams.values()
