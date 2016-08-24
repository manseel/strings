#include "strlib.h"

int search_pattern(char *string, char *pattern)
{
	int i = 0;
	int j;
	int count = 0;

	while(string[i] != '\0') {
		j = 0;
		while(string[i] == pattern[j]) {
			i++;
			j++;
			if (pattern[j] == '\0') {
				count++;
				i--;
			}
		}
		i++;
	}	
	return count;
}
