class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """

        # parameters
        target = len(graph) - 1
        AllPaths2Target = []
        AllPaths = []

        # start computing
        AllPaths.append([0])
        while AllPaths:
            currPath = AllPaths.pop(0)
            for nextNode in graph[currPath[-1]]:
                currPath.append(nextNode)
                if (nextNode == target):
                    AllPaths2Target.append(list(currPath))
                else:
                    AllPaths.append(list(currPath))
                currPath.pop()
        
        return AllPaths2Target
