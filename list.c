#include "shell.h"
/**
 *add_node_end - node to pointed list
 *@head: ptr 2 ptr
 *@dir: str 2 initialize nw node
 *Return: nw || NULL
 */
void add_node_end(list_p **head, const char *dir)
{
	list_p *lt = *head;
	list_p *new = malloc(sizeof(list_p));

	new->next = NULL;

	new->dir = _strdup((char *)dir);
	if (lt)
	{
		while (lt->next)
		lt = lt->next;
		lt->next = new;
	}
	else
		*head = new;
}
/**
 *list_path - linked list of PATH func
 *@env: var env
 *Return: list head
 */
list_p *list_path(char **env)
{
	char *tkn;
	char *path;
	list_p *head;

	head = NULL;
	path = _getenv("PATH", env);

	add_node_end(&head, ".");
	tkn = strtok(path, ":");

	while (tkn != NULL)
	{
		add_node_end(&head, tkn);
		tkn = strtok(NULL, ":");
	}
	return (head);
}
