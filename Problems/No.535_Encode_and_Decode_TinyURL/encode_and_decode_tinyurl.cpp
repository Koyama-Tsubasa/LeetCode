class Solution {

private:
    std::unordered_map<std::string, std::string> T2L;
    std::unordered_map<std::string, std::string> L2T;
    int tinyURL_idx = 1;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        if (L2T.count(longUrl)) return L2T[longUrl];
        std::string new_tinyURL = "http://tinyurl.com/" + std::to_string(tinyURL_idx);
        tinyURL_idx++;
        L2T[longUrl] = new_tinyURL;
        T2L[new_tinyURL] = longUrl;

        return new_tinyURL;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {return T2L[shortUrl];}

};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
