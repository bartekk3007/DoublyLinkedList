#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *prev;
	struct ListNode *next;
};

void addNode(struct ListNode** head, int n)
{
	struct ListNode* vertex = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (vertex)
	{
		vertex->val = n;
		vertex->next = NULL;

		struct ListNode* current = *head;

		if (*head == NULL)
		{
			vertex->prev = NULL;
			*head = vertex;
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = vertex;
			vertex->prev = current;
		}
	}
}

void deleteNode(struct ListNode** head, int n)
{
	struct ListNode* current = *head;
	while (current != NULL && current->val != n)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		return;
	}
	else
	{
		if (current == *head && current->next == NULL)
		{
			free(*head);
			*head = NULL;
		}
		else if (current->prev == NULL)
		{
			*head = current->next;
			(*head)->prev = NULL;
			free(current);
		}
		else if (current->next == NULL)
		{
			struct ListNode* temp = current->prev;
			temp->next = NULL;
			free(current);
		}
		else
		{
			struct ListNode* back = current->prev;
			struct ListNode* forward = current->next;
			back->next = forward;
			forward->prev = back;
			free(current);
		}
	}
}

void traverseList(struct ListNode* head)
{
	printf("Lista ");
	while (head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

void freeList(struct ListNode* head)
{
	struct ListNode* tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main(void)
{
	struct ListNode *head = NULL;
	addNode(&head, 5);
	addNode(&head, 8);
	addNode(&head, 13);
	addNode(&head, 21);
	addNode(&head, 34);
	addNode(&head, 55);

	traverseList(head);

	deleteNode(&head, 5);
	deleteNode(&head, 8);

	traverseList(head);

	freeList(head);

	return 0;
}