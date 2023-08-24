#include "shell.h"
/**
* _strlen - ret len of a string
* @s: char
* Return: length of string
*/
int _strlen(char *s)
{
	int lenth;

	lenth = 0;
	while (s[lenth] != '\0')
		lenth++;
	return (lenth);
}
/**
 *_strcat - concatenates two strs
 *@s1: point to str 1
 *@s2: point to str 2
 *Return: pointer to pointer
 */
char *_strcat(char *s1, char *s2)
{
	char *cat;
	int x, y, z;

	for (x = 0; s1 && s1[x]; ++x)
		;
	for (y = 0; s2 && s2[y]; ++y)
		;
	cat = (char *)malloc((x + y + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	z = 0;
	for (x = 0; s1 && s1[x]; ++x)
	{
		cat[z] = s1[x];
		++z;
	}
	for (y = 0; s2 && s2[y]; ++y)
	{
		cat[z] = s2[y];
		++z;
	}
	cat[z] = '\0';
	return (cat);
}
/**
*_strdup - pointer to new allocated mem
*@str: str
*Return:  pointer
*/
char *_strdup(char *str)
{
	int x, j;
	char *dup;

	if (str == NULL)
		return (NULL);
	for (x = 0; str[x]; x++)
		;
	dup = (char *)malloc((x + 1) * sizeof(char));
	if (dup == NULL)
		return (dup);
	for (j = 0; j <= x; ++j)
		dup[j] = str[j];
	return (dup);
}
/**
* _strcmp - compares strs
* @s1: string 1
* @s2: string 2
* Return: difference
*/
int _strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
}

/**
*_strncpy - concatenates strs
* @dest: string 1
* @src: string 2
* @n: bytes
* Return: pointer to string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int s;

	for (s = 0; (s < n) && (*(src + s) != '\0'); s++)
		*(dest + s) = *(src + s);
	for (; s < n; s++)
		*(dest + s) = '\0';
	return (dest);
}

