class Solution(object):
    def minimumCost(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        
        def find_root(node):
            if (parent[node] == -1):
                return node
            else:
                parent[node] = find_root(parent[node])
                return parent[node]

        def union_set(n1, n2):
            root1, root2 = find_root(n1), find_root(n2)
            
            if (root1 == root2):
                return
            
            if (depth[root1] < depth[root2]):
                root1, root2 = root2, root1
            parent[root2] = root1
            if (depth[root1] == depth[root2]):
                depth[root1] += 1

        
        depth, parent = [0]*n, [-1]*n
        minimumCost = [-1]*n
        ans = []

        for n1, n2, _ in edges:
            union_set(n1, n2)
        for n1, n2, w in edges:
            minimumCost[find_root(n1)] &= w

        for n1, n2 in query:
            n1_root, n2_root = find_root(n1), find_root(n2)

            if (n1_root != n2_root):
                ans.append(-1)
            else:
                ans.append(minimumCost[n1_root])

        return ans
