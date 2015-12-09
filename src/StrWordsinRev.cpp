/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	
	int count = 0, space = 0, i;
	for (i = 0; i < len; i++){
		if (input[i] == ' ')
			space++;
		else
			count++;
	}
	if (space == count - 1){
		char temp = '\0';
		for (i = 0; i < len; i++){
			temp = input[i];
			input[i] = input[len - 1];
			input[len - 1] = temp;
			len--;
		}
	}
	else
	{
		int size = len;
		int space = 0;
		int index;
		int flag = 0;
		int j;
		for (int i = 0; i < len; i++){
			if (input[i] != ' ' && input[i + 1] == ' ')
				space++;
			if (input[i] == ' ' && input[i + 1] != ' ')
				index = i;
		}
		if (space != 0){
			int count = 0;
			input[len] = ' ';
			len = len + 1;
			for (j = 0; j < size; j++){
				if (input[j] != ' ' && input[j + 1] == ' ')
					count++;
				else if (count == space - 1){
					input[len] = input[j + 1];
					len++;
				}
				else{
					if (input[j] == ' '){
						input[len] = input[j];
						len++;
					}
				}
			}
			for (int i = 0; input[i] != ' '; i++){
				input[len] = input[i];
				len++;
			}
			for (int i = index + 1, j = 0; i < len; i++){
				input[j] = input[i];
				j++;
			}
			input[j] = '\0';
		}
	}
}
