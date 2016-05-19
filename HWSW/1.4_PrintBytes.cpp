// Print byte representation of data
// HWSW Section 1: Arrays

#include <iostream>
using namespace std;

/**
 * Function that prints byte representation of data 
 * @params {Pointer to char} start - Pointer to the start of the data
 * @params {int} len - Length of the data
 */
void show_bytes(char* start, int len) {

	for (int i = 0; i < len; i++) {
		printf("%p\t0x%.2x\n", start + i, *(start + i));
	}
}

/**
 * Wrapper function that prints byte representation of int 
 * @params {int} x - Number for which we want the byte representation
 */
void show_int(int x) {

	show_bytes((char*) &x, sizeof(int));
}

/**
 * Wrapper function that prints byte representation of char 
 * @params {char} x - Character for which we want the byte representation
 */
void show_char(char x) {

	show_bytes((char*) &x, sizeof(char));
}

/**
 * Wrapper function that prints byte representation of float 
 * @params {float} x - Floating point integer for which we want the byte representation
 */
void show_float(float x) {

	show_bytes((char*) &x, sizeof(float));
}

/**
 * Starting point of the program
 */
int main() {

	int a = 25;
	cout << "Byte representation of integer " << a << endl;
	show_int(a);

	int b = 0x12345678;
	cout << "Byte representation of integer " << b << endl;
	show_int(b);

	char c = 'a';
	cout << "Byte representation of integer " << c << endl;
	show_char(c);

	float d = 1234.32;
	cout << "Byte representation of float " << float(d) << endl;
	show_float(d);
}