class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        // parameters
        vector<vector<string>> Anagrams;
        map<string, vector<string>> mapping;
        string temp;
        
        // start compute
        for (auto str : strs) {
            
            temp = str;
            sort(temp.begin(), temp.end());
            mapping[temp].push_back(str);
            
        }
        for (auto ele : mapping) Anagrams.push_back(ele.second);
        
        return Anagrams;
        
    }
};
