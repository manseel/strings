#include "strlib.h"

#include <stdio.h>

/* Search for a pattern and return the no. of matches */
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

/* Return 1 if palindrome, else 0 */
int palindrome(char *pattern, int len)
{
	int i = 0;
	int j = len;
	
	while (i < j) {
		if (pattern[i] != pattern[j - 1]) {
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}
