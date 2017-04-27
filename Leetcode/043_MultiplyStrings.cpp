#include <string>

class Solution {
public:
    std::string multiply( std::string num1, std::string num2 ) {

        // Final result
        std::string result = "";

        // First initialize the result
        for( int k = 0; k < num1.size() + num2.size(); k++ )
        {
            result = result + '0';
        }
        
        // Start solving
        int carry = 0;
        int tens = 0;
        for( int i = num2.size() - 1; i >= 0; i-- )
        {
            carry = 0;
            int pos = result.size() - 1 - tens;
            for( int j = num1.size() - 1; j >= 0; j-- )
            {
                int prod = (num1[ j ] - '0') * (num2[ i ] - '0') + carry;
                carry = prod / 10;
                int curr = (result[ pos ] - '0') + (prod % 10);
                result[ pos ] = (curr % 10) + '0';
                carry = carry + (curr / 10);
                pos--;
            }
            if( carry ) result[ pos ] = carry + '0';
            tens++;
        }
        
        // Remove all the preceding 0s
        while(result.size() > 1 && result[0] == '0') {
            result = result.substr(1);
        }

        return result;
    }
};