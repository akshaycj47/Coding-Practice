#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings( std::string num1, std::string num2 ) {

        // Final result
        std::string result = "";

        // Initialize the result
        int maxSize = std::max( num1.size(), num2.size() ) + 1;
        for( int i = 0; i < maxSize; i++ )
        {
            result = result + '0';
        }

        // Always make sure that num1 is greater than or equal to num2
        if( num1.size() < num2.size() )
        {
            std::swap( num1, num2 );
        }

        // Start calculation
        // First reverse two numbers to ease calculation
        std::reverse( num1.begin(), num1.end() );
        std::reverse( num2.begin(), num2.end() );
        int carry = 0;
        int pos;
        for( pos = 0; pos < num2.size(); pos++ )
        {
            int sum = (num1[ pos ] - '0') + (num2[ pos ] - '0') + carry;
            carry = sum / 10;
            result[ pos ] = (sum % 10) + '0';
        }

        // Continue calculation till we reach the end of the larger string
        while( pos < num1.size() )
        {
            int sum = num1[ pos ] - '0' + carry;
            carry = sum / 10;
            result[ pos ] = (sum % 10) + '0';
            pos++;
        }
        if( carry ) result[ pos ] = carry + '0';

        // Reverse the result string and original strings
        std::reverse( result.begin(), result.end() );
        std::reverse( num1.begin(), num1.end() );
        std::reverse( num2.begin(), num2.end() );

        // Remove all the preceding 0s
        while( result.size() > 1 && result[ 0 ] == '0' )
        {
            result = result.substr( 1 );
        }

        return result;
    }
};