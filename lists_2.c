#include "main.h"

/**
 * append_var_node - adds a variable at the end
 * of a var_store list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
var_store *append_var_node(var_store **head, int lvar, char *val, int lval)
{
	var_store *new, *temp;

	new = malloc(sizeof(var_store));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_var_list - frees a var_store list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_var_list(var_store **head)
{
	var_store *temp;
	var_store *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
