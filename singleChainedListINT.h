#ifndef LIST_FUNCTIONS
#define	LIST_FUNCTIONS
#define nullptr 0
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;


NODE *addAtBeginning(NODE **pHead, int data)
{
	NODE *newNode = (NODE *)calloc(1, sizeof(NODE));

	newNode->info = data;
	newNode->next = *pHead;
	*pHead = newNode;

	return *pHead;

}

NODE *addAtEnd(NODE **pHead, int data)
{
	NODE *newNode = (NODE *)calloc(1, sizeof(NODE));
	NODE *tmp = *pHead;
	newNode->info = data;

	if (*pHead == nullptr) // If the list is empty
	{
		*pHead = newNode;
		return newNode;
	}
	else
	{
		while (tmp->next) tmp = tmp->next;
		tmp->next = newNode;
		return newNode;
	}
}

NODE *addAfter(NODE *node, int data)
{
	NODE *newNode = (NODE *)calloc(1, sizeof(NODE));
	newNode->info = data;

	if (node->next == nullptr)
		node->next = newNode;
	else
	{
		newNode->next = node->next;
		node->next = newNode;
	}
	return newNode;
}

NODE *addBefore(NODE *node, int data)
{
	NODE *newNode = (NODE*)calloc(1, sizeof(NODE));

	if (node == nullptr) // if the list is empty
	{
		newNode->info = data;
		node->next = newNode;
		return node;
	}
	else
	{
		newNode->info = node->info;
		newNode->next = node->next;
		node->info = data;
		node->next = newNode;
		return node;
	}
}

int deleteAfter(NODE *node)
{
	NODE *tmp = nullptr;
	tmp = node->next;
	if (tmp == nullptr)
	{
		printf("You are not allowed to delete last node!\n");
		return 0;
	}

	node->next = tmp->next;
	free(tmp);
	return 1;
}

int deleteNode(NODE *node)
{
	NODE *tmp = nullptr;
	tmp = node->next;

	if (tmp == nullptr)
	{
		printf("You are not allowed to delete last node!\n");
		return 0;
	}
	else
	{
		node->next = tmp->next;
		node->info = tmp->info;
		free(tmp);
		return 1;
	}
}

void deleteList(NODE **pHead)
{
	if (*pHead == nullptr)
	{
		printf("The list is already empty!\n");
	}
	else
	{
		while (*pHead)
		{
			NODE *tmp = (*pHead)->next;
			free(*pHead);
			*pHead = tmp;
		}
		*pHead = nullptr;
		printf("The list has been deleted!\n");
	}
}

NODE *seqSearch(NODE *pHead, int key)
{
	while (pHead && (pHead->info) != key)
		pHead = pHead->next; //like i++ in basic loops
	return pHead;
}

void printList(NODE *pHead)
{
	if (pHead == nullptr)
	{
		printf("The list is empty. There is nothing to be printed!\n");
	}
	else
	{
		while (pHead)
		{
			printf(" %d", pHead->info+1);
			pHead = pHead->next; //like i++ in basic loops
		}
	printf("\n");
	}
}

void selecSort(NODE *pHead)
{
	for (; pHead && pHead->next; pHead = pHead->next)
	{
		NODE *min=pHead, *j;
		for (j = pHead->next; j; j = j->next)
		{
			if (min->info > j->info)
			{
				min = j;
			}
			if (min != pHead)
			{
				int tmp = pHead->info;
				pHead->info = min->info;
				min->info = tmp;
			}
		}
	}
}

void invertList(NODE **pHead)
{
	NODE *p1 = *pHead, *p2 = nullptr, *p3;
	while (p1)
	{
		p3 = p1->next;
		p1->next = p2;
		p2 = p1;
		p1 = p3;
	}
	*pHead = p2;
}


#endif




