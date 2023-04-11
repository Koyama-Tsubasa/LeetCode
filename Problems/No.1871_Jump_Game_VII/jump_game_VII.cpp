class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        // parameters
        int s_length = s.length();
        std::queue<int> index;

        // start computing
        int MAX_idx = 0;
        index.push(0);
        while (!index.empty()) {

            int idx = index.front();
            index.pop();
            
            for (int i=std::max(idx+minJump, MAX_idx+1);
                     i<std::min(s_length, idx+maxJump+1); i++)
                if (s[i] == '0') {

                    if (i == s_length-1) return true;
                    index.push(i);

                }
            
            MAX_idx = idx + maxJump;

        }

        return false;

    }
};
