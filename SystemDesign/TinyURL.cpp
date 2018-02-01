#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>

class Solution {
private:
    std::string keystroke = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::unordered_map<std::string, std::string> m;
    
public:

    std::string getRandomKey() {
        
        srand(time(NULL));
        std::string key = "";
        for(int i = 0; i < 6; i++) {
            int idx = rand() % 62;
            key += keystroke[idx];
        }
        return key;
    }
    
    // 62^6 URLs can be encoded using this scheme
    // Encodes a URL to a shortened URL.
    std::string encode(std::string longUrl) {
        
        std::string key = getRandomKey();
        while(m.find(key) != m.end()) {
            key = getRandomKey();
        }
        
        m[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(std::string shortUrl) {
        
        std::string key = shortUrl.substr(19, 6);
        return m[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
