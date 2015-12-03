/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int i = 0;
	int digit_count = 0;
	int int_number = number;
	float after_decimal = number - int_number;
	if (int_number < 0){
		str[0] = '-';
		int_number = -number;
		after_decimal = -after_decimal;
		digit_count++;
	}
	int num = int_number;
	while (num > 0){
		digit_count++;
		num = num / 10;
	}
	int count = digit_count - 1;
	while (int_number > 0){
		int rem = int_number % 10;
		str[count] = (rem + '0');
		count--;
		int_number = int_number / 10;
	}
	int j;
	if (after_decimal > 0){
		str[digit_count] = '.';
		for (j = 0; j < afterdecimal; j++){
			digit_count++;
			float decimal_num = after_decimal * 10.0;
			int int_num = decimal_num;
			str[digit_count] = int_num + '0';
			after_decimal = decimal_num - int_num;
		}
	}
}
