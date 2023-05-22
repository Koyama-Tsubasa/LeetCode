class Solution {
public:

    // find the answer for each equation using DFS
    double DFS(double val, std::string node, std::string dest, std::set<string> &visited,
               std::unordered_map<std::string, std::unordered_map<std::string, double>> &Graph) {

        // check if visit the destination
        if ((node == dest) && (Graph.find(node) != Graph.end())) return val;
        else {

            double temp;
            for (auto &[next_node, ans]: Graph[node]) 
                if (visited.count(next_node) == 0) {

                    visited.insert(next_node);
                    temp = DFS(val*ans, next_node, dest, visited, Graph);
                    if (temp != -1.0) return temp;

                }
            
            return -1.0;

        }

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // parameters
        std::vector<double> Equations;

        // start computing
        // build Equation Graph
        std::unordered_map<std::string, std::unordered_map<std::string, double>> Graph;
        for (int i=0; i<equations.size(); i++) {

            Graph[equations[i][0]][equations[i][1]] = values[i];
            Graph[equations[i][1]][equations[i][0]] = 1/values[i];

        }

        // start compute for each equation using DFS
        std::set<std::string> visited;
        for (auto &equation: queries) {

            visited.clear();
            Equations.push_back(DFS(1, equation[0], equation[1], visited, Graph));

        }

        return Equations;

    }
};
