class Solution {
public:
    string convert(string s, int numRows) {

    	if (numRows == 1 || s.size() == 0) {
    		return s;
    	}
    	int n = s.size();
    	int nR = numRows;
    	string ans = "";
    
    	for (int row = 0; row < nR; row++) {
    		for (int i = row; i < n; i = i + 2 * nR - 2) {
    			ans = ans + s[i];
    			int next = i + 2 * nR - 2 - 2 * row;
    			if ((next < i + 2 * nR - 2) && (next < n) && (next != i)) {
    				ans = ans + s[next];
    			}
    		}
    	}
    	return ans;
    }
};