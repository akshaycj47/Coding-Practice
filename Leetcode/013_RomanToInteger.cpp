class Solution {
public:
    int romanToInt(string s) {
        
        std::map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        int ans = 0;
        int curr = 0;
        while (s.size() > 0) {
            if (m[s.back()] >= curr) {
                curr = m[s.back()];
                ans = ans + m[s.back()];
            }
            else {
                ans = ans - m[s.back()];
            }
            s.pop_back();
        }
        return ans;
    }
};