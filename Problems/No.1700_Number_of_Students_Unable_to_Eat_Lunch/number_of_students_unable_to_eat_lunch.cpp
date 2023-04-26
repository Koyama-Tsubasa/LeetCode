class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        // parameter
        std::queue<int> sQueue;

        // start computing
        for (auto &s: students) sQueue.push(s);
        
        int cnt;
        while (!sQueue.empty())
            for (auto &sandwich: sandwiches) {
                
                cnt = 0;
                while (sQueue.front() != sandwich) {

                    sQueue.push(sQueue.front());
                    sQueue.pop();
                    cnt++;
                    if (cnt == sQueue.size()) return sQueue.size();

                }
                sQueue.pop();

            }
        
        return 0;

    }
};
