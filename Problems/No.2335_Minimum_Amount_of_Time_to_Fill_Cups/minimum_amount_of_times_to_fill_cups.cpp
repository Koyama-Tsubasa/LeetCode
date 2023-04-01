class Solution {
public:
    int fillCups(vector<int>& amount) {
        
        // parameters
        std::priority_queue<int> CupsAmount;
        int times = 0;

        // start computing
        for (auto &cup: amount) if (cup > 0) CupsAmount.push(cup);
        while (!CupsAmount.empty()) {

            auto cup_largest = CupsAmount.top() - 1;
            CupsAmount.pop();

            if (!CupsAmount.empty()) {

                auto cup_second = CupsAmount.top() - 1;
                CupsAmount.pop();
                if (cup_second > 0) CupsAmount.push(cup_second);

            }

            if (cup_largest > 0) CupsAmount.push(cup_largest);
            times++;

        }

        return times;

    }
};
