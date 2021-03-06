class Solution {
public:
    string intToRoman(int num) {
        
        int M = 1000;
        int D = 500;
        int C = 100;
        int L = 50;
        int X = 10;
        int V = 5;
        int I = 1;
        std::string ans;
        
        while (num > 0) {
            if (num >= 1000) {
                num = num - 1000;
                ans = ans + "M";
            }
            else if (num >= 900 && num < 1000) {
                num = num - 900;
                ans = ans + "CM";
            }
            else if (num >= 500 && num < 900) {
                num = num - 500;
                ans = ans + "D";
            }
            else if (num >= 400 && num < 500) {
                num = num - 400;
                ans = ans + "CD";
            }
            else if (num >= 100 && num < 400) {
                num = num - 100;
                ans = ans + "C";
            }
            else if (num >= 90 && num < 100) {
                num = num - 90;
                ans = ans + "XC";
            }
            else if (num >= 50 && num < 90) {
                num = num - 50;
                ans = ans + "L";
            }
            else if (num >= 40 && num < 50) {
                num = num - 40;
                ans = ans + "XL";
            }
            else if (num >= 10 && num < 40) {
                num = num - 10;
                ans = ans + "X";
            }
            else if (num >= 9 && num < 10) {
                num = num - 9;
                ans = ans + "IX";
            }
            else if (num >= 5 && num < 9) {
                num = num - 5;
                ans = ans + "V";
            }
            else if (num >= 4 && num < 5) {
                num = num - 4;
                ans = ans + "IV";
            }
            else {
                num = num - 1;
                ans = ans + "I";
            }
        }
        return ans;
    }
};