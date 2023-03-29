class Solution {
public:
    string frequencySort(string s) {
        
        // parameters
        std::string sorted_string = "";
        std::unordered_map<char, int> char_num_mapping;
        std::vector<std::pair<int, char>> frequency;

        // start computing
        // calculate the number of each characters
        for (auto &c: s) char_num_mapping[c]++;

        // create the MAX-Heap from the mapping result
        for (auto &char_num: char_num_mapping) 
            frequency.push_back({char_num.second, char_num.first});
        std::make_heap(frequency.begin(), frequency.end());

        // create sorted string
        while (!frequency.empty()) {

            auto [curr_n, curr_c] = frequency.front();
            std::pop_heap(frequency.begin(), frequency.end());
            frequency.pop_back();
            for (int i=0; i<curr_n; i++) sorted_string += curr_c;

        }

        return sorted_string;

    }
};
