class Solution {
public:

    // check if the subIP is valid
    bool check_valid (std::string check_IP) {

        if (check_IP.length() == 1) return true;
        else if (check_IP[0] == '0') return false;
        else return (std::stoi(check_IP) <= 255);

    }

    vector<string> restoreIpAddresses(string s) {
        
        // parameter
        int s_length = s.length();
        string first, second, third, forth;
        std::vector<std::string> possibleIP;

        // start computing
        if (s_length > 12) return {};
        for (int len1=1; len1<=3; len1++) {
            for (int len2=1; len2<=3; len2++) {
                for (int len3=1; len3<=3; len3++) {
                    if (((len1+len2+len3) < s_length) &&
                        (s_length <= (len1+len2+len3+3))) {

                        first = s.substr(0, len1);
                        second = s.substr(len1, len2);
                        third = s.substr(len1+len2, len3);
                        forth = s.substr(len1+len2+len3);

                        if (check_valid(first) && check_valid(second) &&
                            check_valid(third) && check_valid(forth)) 
                            possibleIP.push_back(first+"."+second+"."+third+"."+forth);

                    }
                }
            }
        }

        return possibleIP;

    }
};
