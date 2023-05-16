class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        // parameters
        std::vector<std::string> RepeatedDNA;
        std::unordered_map<std::string, int> DNA_cnt;

        // start computing
        if (s.length() <= 10) return {};
        for (int i=0; i<=s.length()-10; i++) {

            std::string sub_DNA = s.substr(i, 10);
            DNA_cnt[sub_DNA]++;

        }
        for (auto &[sDNA, cnt]: DNA_cnt)
            if (cnt > 1) RepeatedDNA.push_back(sDNA);
        
        return RepeatedDNA;

    }
};
