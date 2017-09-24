class Solution {
public:
    int numTreesUtil(int n, int* L) {
        
        if(L[n] != -1) {
            return L[n];
        }
        
        int count = 0;
        for(int i = 1; i <= n; i++) {
            count += numTreesUtil(i - 1, L) * numTreesUtil(n - i, L);
        }
        
        L[n] = count;
        return count;
    }
    
    int numTrees(int n) {
        
        // Solve it using DP, filling up the array
        
        // Base case
        if(n <= 1) return 1;
        
        // Create an array to store the DP values
        int* L = new int[n + 1];
        L[0] = 1;
        L[1] = 1;
        
        // Fill the remaining with -1 (indicating that calculation is not yet done)
        for(int i = 2; i <= n; i++) {
            L[i] = -1;
        }
        
        return numTreesUtil(n, L);    
    }
};