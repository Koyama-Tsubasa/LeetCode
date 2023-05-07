class Solution {
public:
    string greatestLetter(string s) {
        
        // parameters
        char greatest_letter = '@';
        std::unordered_set<char> letter_set;
        
        // start computing
        for (auto &c: s) {

            if (!std::isalpha(c)) continue;

            char check;
            if (std::islower(c) && (letter_set.find(std::toupper(c)) != letter_set.end())) check = std::toupper(c);
            else if (std::isupper(c) && (letter_set.find(std::tolower(c)) != letter_set.end())) check = c;

            greatest_letter = (check > greatest_letter) ? check : greatest_letter;
            letter_set.insert(c);

        }

        return (greatest_letter != '@') ? std::string (1, greatest_letter) : "";

    }
};
