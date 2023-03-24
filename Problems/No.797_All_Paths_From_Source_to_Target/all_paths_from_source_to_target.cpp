class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        // parameters
        std::vector<std::vector<int>> AllPaths2Target;
        std::queue<std::vector<int>> AllPaths;

        // start computing
        AllPaths.push({0});
        while (!AllPaths.empty()) {

            auto currPath = AllPaths.front();
            AllPaths.pop();

            for (auto nextNode: graph[currPath.back()]) {

                currPath.push_back(nextNode);
                if (nextNode == graph.size()-1) AllPaths2Target.push_back(currPath);
                else AllPaths.push(currPath);
                currPath.pop_back();

            }

        }

        return AllPaths2Target;

    }
};
