class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        // start computing
        auto edge0 = edges[0];
        auto edge1 = edges[1];

        if ((edge0[0] == edge1[0]) || (edge0[0] == edge1[1])) return edge0[0];
        else return edge0[1];

    }
};
