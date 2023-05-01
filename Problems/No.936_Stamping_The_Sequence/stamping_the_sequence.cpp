class Solution {
public:

    // check if the target idx from i can be replaced by the stamp
    bool Replacable(int start_idx, std::string stamp, std::string target) {
       
        for (int i=0; i<stamp.length(); i++)
            if ((target[start_idx + i] != stamp[i]) && (target[start_idx + i] != '?'))
                return false;
        return true;

    }

    vector<int> movesToStamp(string stamp, string target) {
        
        // parameters
        std::vector<int> stamp_idx;
        int stamp_len = stamp.length();
        int target_len = target.length();
        int replace_count = 0;
        std::vector<bool> replaced(target_len, false);

        // start computing
        while (replace_count < target_len) {

            bool changed = false;
            for (int i=0; i<=target_len-stamp_len; i++) {

                if (!replaced[i] && Replacable(i, stamp, target)) {
             
                    // replace the corresponding stamp in target to ? & count the replaced character num
                    changed = true;
                    replaced[i] = true;
                    for (int j=0; j<stamp_len; j++) 
                        if (target[i+j] != '?') {

                            target[i+j] = '?';
                            replace_count++;

                        }
                    stamp_idx.push_back(i);
                    if (replace_count == target_len) break;
                    
                }

            }
            if (!changed) return {};

        }

        std::reverse(stamp_idx.begin(), stamp_idx.end());
        return stamp_idx;

    }
};
