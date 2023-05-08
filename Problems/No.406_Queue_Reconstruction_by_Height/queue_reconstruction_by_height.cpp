class Solution {
public:

    static bool compare(std::vector<int> &a, std::vector<int> &b) {

        if (a[0] != b[0]) return (a[0] > b[0]);
        else return (a[1] < b[1]);

    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        // reference:
        // https://leetcode.com/problems/queue-reconstruction-by-height/solutions/3356753/easy-c-solution-using-sorting/

        // parameter
        std::vector<std::vector<int>> reconstructed_Q;

        // start computing
        std::sort(people.begin(), people.end(), compare);
        for (auto &person: people) 
            reconstructed_Q.insert(reconstructed_Q.begin()+person[1], person);
        
        return reconstructed_Q;

    }
};
