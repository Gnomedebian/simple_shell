#include "shell.h"
/**
*free_loop - free double pointers
*@arr: array of pointers
*/
void free_loop(char **arr)
{
	int lenth;

	for (lenth = 0; arr[lenth]; lenth++)
		free(arr[lenth]);
	free(arr);
}

/**
 *free_list - frees listint_t
 *@head: head of a listint_t
 */
void free_list(list_p *head)
{
	list_p *prv;

	while (head)
	{
		free(head->dir);
		prv = head;
		head = head->next;
		free(prv);
	}
}
