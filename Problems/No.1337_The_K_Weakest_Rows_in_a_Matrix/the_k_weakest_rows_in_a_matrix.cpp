class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // parameters
        std::priority_queue<std::pair<int, int>> Row_Strength;
        std::vector<int> kWeakestRows;

        // start computing
        // calculate soldiers in each row & order them
        for (int i=0; i<mat.size(); i++) {

            auto soldiers = 0;
            for (int s=0; s<mat[i].size(); s++) {

                if (mat[i][s] == 1) soldiers++;
                else break;

            }

            Row_Strength.push({soldiers, i});
            if (i >= k) Row_Strength.pop();

        }

        // k weakest rows
        while (!Row_Strength.empty()) {

            kWeakestRows.insert(kWeakestRows.begin(), Row_Strength.top().second);
            Row_Strength.pop();

        }

        return kWeakestRows;

    }
};
