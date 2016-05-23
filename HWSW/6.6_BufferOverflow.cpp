// Demonstration of buffer overflow
// HWSW Section 6: Buffer Overflows

#include <cstdio>
#include <iostream>
using namespace std;

/**
 * Function that demonstrates buffer overflow
 */
void echo() {

	char buff[4];					// Way too small buffer
	gets(buff);
	puts(buff);
}

int main() {

	printf("Type a string:\n");
	echo();
	return 0;
}