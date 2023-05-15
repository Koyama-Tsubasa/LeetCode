class Codec:

    def __init__(self):
        self.T2L = {}
        self.L2T = {}
        self.tinyURL_idx = 1

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        if longUrl in self.L2T:
            return self.L2T[longUrl]
        new_tinyURL = "http://tinyurl.com/" + str(self.tinyURL_idx)
        self.tinyURL_idx += 1
        self.L2T[longUrl] = new_tinyURL
        self.T2L[new_tinyURL] = longUrl
    
        return new_tinyURL
        
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.T2L[shortUrl]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
