#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct path_s
{
	char *str;
	struct path_s *next;
} path_t;

path_t *add_node(path_t **head, const char *str)
{
	path_t *new_node = malloc(sizeof(path_t));

	/* return null if malloc fails */
	if (new_node == NULL)
		return (NULL);

	/* add data to new node */
	new_node->str = strdup(str);
	new_node->next = *head; // new_node->next = h;

	/* update head to point to new node */
	*head = new_node; // h = new_node;

	return (new_node);
}

size_t print_list(const path_t *h)
{
	int nodes = 0; /* number of nodes */

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("%s\n", h->str);
		}
	nodes++;
	h = h->next; /* move to the next node */
	}
	return (nodes);
}

int main()
{
	char *full_path, *path;
	path_t *head;
			
	full_path = getenv("PATH");
	path = strtok(full_path, ":");
	while (path != NULL)
	{
        head = add_node(&head, path);
		path = strtok(NULL, ":");
	}
	
	print_list(head);
	return (0);
}
