#include <stdio.h>
#include <stdlib.h>

typedef struct segment
{
	int info;
	struct segment *next;
}SEGMENT;

int isNotEmpty(SEGMENT *front)
{
	if(front!=NULL)
		return 1;
}

void addToQueue(SEGMENT **fron, SEGMENT **rear, int data)
{
	SEGMENT *newSegment = (SEGMENT*)calloc(1, sizeof(SEGMENT));
	newSegment->info = data;

	if ((*fron) == 0)
		*fron = *rear = newSegment;
	else
	{
		(*rear)->next = newSegment;
		(*rear) = newSegment;
	}
}

int deleteFromQueue(SEGMENT **fron, SEGMENT **rear, int *dataPointer)
{
	if (*fron == 0)
	{
		return 0;
	}
	SEGMENT *tmp = *fron;
	*dataPointer = (*fron)->info;

	if ((*fron) == (*rear))
		*fron = *rear = 0;
	(*fron) = tmp->next;
	free(tmp);
	return 1;
}

void deleteQueue(SEGMENT **fron, SEGMENT **rear)
{
	int pom;
	while (deleteFromQueue(&(*fron), &(*rear), &pom));
}

int elementsInQueue(SEGMENT *fron)
{
	if (fron == 0)
		return 0;
	int numberOfElements=0;
	while (fron)
	{
		numberOfElements++;
		fron = fron->next;
	}
	return numberOfElements;
}

void printQueue(SEGMENT *fron)
{
	if (fron == 0)
		printf("Red je prazan!\n");
	while (fron)
	{
		printf("|%d| ", fron->info);
		fron = fron->next;
	}
	printf("\n");
}

void peekQueue(SEGMENT *fron)
{
	if (fron == 0)
	{
		printf("Red je prazan!\n");
		return;
	}
	printf("|%d|\n", fron->info);
}

void sizeOfQueue(SEGMENT *fron)
{
	int numberOfElements = elementsInQueue(fron);
	int size = numberOfElements * sizeof(int);
	printf("Red zauzima %d B u memoriji racunara!\n", size);
}

void storeQueueInFile(SEGMENT *fron, SEGMENT *rear, FILE *stream)
{
	if (!stream)
	{
		printf("Postoji problem sa otvaranjem datoteke!\n");
		return;
	}
	if ((fron)==0)
	{
		printf("Red je prazan, nije moguc upis u datoteku!\n");
		return;
	}
	int i = 0;
	int numberOfElements = elementsInQueue(fron);
	int *elementsArray = (int*)calloc(numberOfElements, sizeof(int));
	while (fron)
	{
		elementsArray[i] = fron->info;
		fron = fron->next;
		i++;
	}

	fwrite(elementsArray, sizeof(int), numberOfElements, stream);
	printf("Sadrzaj reda [ukupno %d elemenata] je upisan u datoteku!\n", numberOfElements);
	free(elementsArray);
}

void loadQueueFromFile(SEGMENT **fron,SEGMENT **rear, FILE *stream, int numberOfElements)
{
	int *elementsArray = (int*)calloc(numberOfElements, sizeof(int));
	if (!fread(elementsArray, sizeof(int),numberOfElements, stream))
	{
		printf("Nije moguce ucitati podatke iz datoteke!\n");
	}
	else
	{
		for (int i = 0; i < numberOfElements; i++)
		{
			addToQueue(&(*fron), &(*rear), elementsArray[i]);
		}
		printf("Sadrzaj datoteke [ukupno %d elemenata] je dodano u red!\n", numberOfElements);
		free(elementsArray);
	}
}

