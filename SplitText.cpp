#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CountInclude(char str[], char c)
{
	int count = 0;
	int l = strlen(str); 
	int i = 0;
	for (i = 1; i < l; i++)
	{
		if (str[i] == c)
		{
			if (str[i - 1] != c) 
				count++;
		}
	}
	if (str[l - 1] != c)
		count++;
	return count;
}

void WordsLen(char* str, char c, 
	int** wl, int* count)
{
	*count = CountInclude(str, c);
	*wl = (int*)calloc(*count, sizeof(int));

	int l = strlen(str);
	int i = 0, t = 0, start = 0;
	for (i = 1; i < l; i++)
	{
		if (str[i] == c)
		{
			if (str[i - 1] != c)
			{ 
				(*wl)[t] = i - start;
				start = i + 1;
				t++;
			}	
			else
			{
				start = i + 1;
			}
		}
	}
	if (str[l - 1] != c)
	{
		(*wl)[t] = i - start;
	}
}

void PrintVector(int* mas, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("mas[%d] = %d\n",i, mas[i]);
}

void Split(char* str, char c, char*** res,int* count)
{

	int* wl = 0;
	WordsLen(str, c, &wl, count);
	(*res) = (char**)malloc(sizeof(char*)*(*count));

	int l = strlen(str);
	int i = 0, t = 0, start = 0;
	for (i = 1; i < l; i++)
	{
		if (str[i] == c)
		{
			if (str[i - 1] != c)
			{
				int j = 0;
				(*res)[t] = (char*)malloc(sizeof(char) * (wl[t] + 1));
				for (j = 0; j < wl[t]; j++)
					(*res)[t][j] = str[start + j];
				(*res)[t][wl[t]] = 0;
				start = i + 1;
				t++;
			}
			else
			{
				start = i + 1;
			}
		}
	}
	if (str[l - 1] != c)
	{
		int j = 0;
		(*res)[t] = (char*)malloc(sizeof(char) * (wl[t] + 1));
		for (j = 0; j < wl[t]; j++)
			(*res)[t][j] = str[start + j];
		(*res)[t][wl[t]] = 0;
	}
}

void PrintText(char** s, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%s\n", s[i]);
}

char* GoToHome(char** s, int n)
{
	int len = 0, i = 0, j = 0, k = 0;
	for (i = 0; i < n; i++)
	{
		len += strlen(s[i]);
	}
	len += n;
	char* res = (char*)malloc(len * sizeof(char));
	j = 0;
	for (i = 0; i < n; i++)
	{
		int l = strlen(s[i]);
		for (k = 0; k < l; k++)
		{
			res[j] = s[i][k];
			j++;
		}
		res[j] = ' ';
		j++;
	}
	res[j] = 0;
	return res;
}

int main() 
{
	//char str[] = "                                  ";
	char str[] = "  H ello    World!!! Hello World!!! Hello World!!!";
	printf("%s\n", str);
	int c = CountInclude(str, ' ');
	printf("CountInclude in %s = %d", str, c);
	int* wl = 0;
	WordsLen(str, ' ', &wl, &c);
	PrintVector(wl, c);
	char** text = 0;
	Split(str, ' ', &text, &c);
	PrintText(text, c);

	printf("%s\n", GoToHome(text, c));

	return 0; 
}