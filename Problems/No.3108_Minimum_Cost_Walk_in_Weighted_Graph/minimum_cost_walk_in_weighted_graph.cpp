class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {

        vector<int> minimumCost(n, -1);
        vector<int> ans;

        depth.resize(n, 0);
        parent.resize(n, -1);

        for (auto edge: edges) union_set(edge[0], edge[1]);
        for (auto edge: edges) {

            int root = find_root(edge[0]);
            minimumCost[root] &= edge[2];

        }

        for (auto query: queries) {

            int n1_root = find_root(query[0]);
            int n2_root = find_root(query[1]);

            if (n1_root != n2_root) ans.push_back(-1);
            else ans.push_back(minimumCost[n1_root]);

        }

        return ans;

    }

private:
    vector<int> depth, parent;
    int find_root(int node) {

        if (parent[node] == -1) return node;
        else return parent[node] = find_root(parent[node]);

    }
    void union_set(int n1, int n2) {

        int root1 = find_root(n1);
        int root2 = find_root(n2);

        if (root1 == root2) return;
        
        if (depth[root1] < depth[root2]) swap(root1, root2);
        parent[root2] = root1;
        if (depth[root1] == depth[root2]) depth[root1]++;

    }

};
