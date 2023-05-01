class Solution {
public:

    // check if the substring is all '?'
    bool AllQ(std::string &checking_str) {
       
        for (auto &c: checking_str) if (c != '?') return false;
        return true;

    }

    // check if the target idx from i can be replaced by the stamp
    bool Replacable(std::string &temp, std::string &stamp) {
       
        for (int i=0; i<stamp.length(); i++)
            if ((temp[i] != stamp[i]) && (temp[i] != '?'))
                return false;
        return true;

    }

    vector<int> movesToStamp(string stamp, string target) {
        
        // parameters
        std::vector<int> stamp_idx;
        int stamp_len = stamp.length();
        int target_len = target.length();
        bool changed = true;

        // start computing
        while (changed) {

            changed = false;
            for (int i=0; i<=target_len-stamp_len; i++) {

                std::string temp_str = target.substr(i, stamp_len);
                if (AllQ(temp_str)) continue;
                if (Replacable(temp_str, stamp)) {
             
                    // replace the corresponding stamp in target to ? & count the replaced character num
                    changed = true;
                    for (int j=0; j<stamp_len; j++) 
                        if (target[i+j] != '?') target[i+j] = '?';
                    stamp_idx.push_back(i);
                    
                }

            }

        }

        if (AllQ(target)) {

            std::reverse(stamp_idx.begin(), stamp_idx.end());
            return stamp_idx;

        }
        else return {};

    }
};
