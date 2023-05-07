class Solution {
public:
    string greatestLetter(string s) {
        
        // parameters
        char greatest_letter = '@';
        std::unordered_set<char> letter_set;
        
        // start computing
        for (auto &c: s) {

            if (!std::isalpha(c)) continue;
            if (std::islower(c)) {

                char upper_c = std::toupper(c);
                if (letter_set.find(upper_c) != letter_set.end())
                    greatest_letter = (upper_c > greatest_letter) ? upper_c : greatest_letter;

            }
            else if (letter_set.find(std::tolower(c)) != letter_set.end())
                    greatest_letter = (c > greatest_letter) ? c : greatest_letter;

            letter_set.insert(c);

        }

        return (greatest_letter != '@') ? std::string (1, greatest_letter) : "";

    }
};
