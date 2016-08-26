#include "strlib.h"

#include <stdio.h>
#include <ctype.h>

/* for getch() and ungetch() */
#define BUFSIZE 128
char buff[BUFSIZE];
int bufp = 0;

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

/* Print entire sentence in inverse */
void inverse_line(char *string, int len)
{
	
	while (--len >= 0)
		putchar(string[len]);
}	

int isspacem(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return 1;
	else
		return 0;
}


int getch(void)
{
	return (bufp > 0) ? buff[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("Ungetch: Buffer exceeded\n");
	else
		buff[bufp++] = c;
}

/* Fill the buffer with a word */
int getword(char word[], int lim)
{
	int c;
	char *w = word;

	while(isspacem(c = getch())) 
		;

	if (c != EOF)
		*w++ = c;

	if(!isalpha(c)) {
		*w++ = '\0';
		return c;
	}

	for(;--lim > 0; w++)
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
	}
	*w = '\0';
	return word[0];	
}

