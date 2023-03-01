class Solution {
public:

    // create combinations
    void create_combinations(int start, int end, int size, std::vector<int> &comb, std::vector<std::vector<int>> &combs) {

        if (comb.size() == size) combs.push_back(comb);
        else {

            for (int i=start; i<=end; i++) {

                comb.push_back(i);
                create_combinations(i+1, end, size, comb, combs);
                comb.pop_back();

            }

        }

    }

    vector<vector<int>> combine(int n, int k) {
        
        // parameters
        std::vector<std::vector<int>> combinations;
        std::vector<int> combination;

        // start computing
        create_combinations(1, n, k, combination, combinations);

        return combinations;

    }
};
