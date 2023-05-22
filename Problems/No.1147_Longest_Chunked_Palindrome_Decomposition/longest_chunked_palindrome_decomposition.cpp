class Solution {
public:
    int longestDecomposition(string text) {
        
        // parameters
        int left_idx = 0, right_idx = text.length();
        int sub_length = 0, subtext_cnt = 0;

        // start computing
        while (left_idx <= right_idx) {

            sub_length++;
            if (text.compare(left_idx, sub_length, text, right_idx-sub_length, sub_length) == 0) {

                left_idx += sub_length;
                right_idx -= sub_length;
                sub_length = 0;
                
                if (left_idx < right_idx) subtext_cnt += 2;
                else subtext_cnt++;

            }

        }

        return subtext_cnt;

    }
};
