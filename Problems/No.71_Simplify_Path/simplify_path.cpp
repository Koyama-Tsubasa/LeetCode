class Solution {
public:
    string simplifyPath(string path) {
        
        // parameters
        std::stack<std::string> relative_paths;
        std::stringstream ss(path);
        std::string temp, simplifiedPath = "";

        // start computing

        // split the path into relative paths
        while (getline(ss, temp, '/')) 
            if (temp != "") {

                if (temp == ".") continue;
                else if ((temp == "..") && (!relative_paths.empty())) relative_paths.pop();
                else relative_paths.push(temp);

            }
        
        // merge relative paths
        while (!relative_paths.empty()) {

            simplifiedPath = "/" + relative_paths.top() + simplifiedPath;
            relative_paths.pop();

        }

        if (simplifiedPath == "") return "/";
        return simplifiedPath;
        
    }
};
