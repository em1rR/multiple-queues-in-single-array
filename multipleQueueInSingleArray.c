#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 100
int maxSize = 20;
int array[20];
int firstFront = 0;
int firstRear = 0;
int secondFront = 10;
int secondRear = 10;

void enqueue(char queue[], int value) 
{
	if(strcmp(queue, "FIRST") == 0)		// check for queue first or second
	{
		if(firstFront == 0 && firstRear == 0) // insert first element
		{
			printf("%d\tis inserted to queue %s\n", value, queue);
			array[firstRear++] = value;
		}
		else if(firstRear < secondFront - 1)	// insert after first element
		{
			printf("%d\tis inserted to queue %s\n", value, queue);
			array[firstRear++] = value;
		}
		else	// queue is full
		{
			printf("QUEUE %s is full\n", queue);
		}
		
	} 
	else if(strcmp(queue, "SECOND") == 0)
	{
		if(secondFront == 10 && secondRear == 10) // insert first element
		{
			printf("%d\tis inserted to queue %s\n", value, queue);
			array[secondRear++] = value;
		}
		else if(secondRear < maxSize)	// insert after first element
		{
			printf("%d\tis inserted to queue %s\n", value, queue);
			array[secondRear++] = value;
		}
		else
		{
			printf("QUEUE %s is full\n", queue);
		}
	}
}


void dequeue(char queue[])
{
	if(strcmp(queue, "FIRST") == 0)		//check for queue first or second
	{
		if(firstFront == firstRear)
		{
			printf("Queue %s is empty\n", queue);
		}
		else
		{
			firstFront++;	
		}
	}
	else if(strcmp(queue, "SECOND") == 0)
	{
		if(secondFront == secondRear)
		{
			printf("Queue %s is empty\n", queue);
		}
		else
		{
			secondFront++;	
		}
	}
}

void print(char queue[])
{
	if(strcmp(queue, "FIRST") == 0)		// check for queue first or second
	{
		int size;
		size = firstRear - firstFront;
		printf("QUEUE:%s \t FRONT:%d \t REAR:%d \t SIZE:%d\n", queue, firstFront, firstRear, size);
		if(size == 0)
		{
			printf("NO_CONTENT");
		}
		else
		{
			int i;
			for(i=firstFront; i<firstRear; i++)
			{
				printf("%d\t", array[i]);
			}
		}
		printf("\n");
	}
	else if(strcmp(queue, "SECOND") == 0)
	{
		int size;
		size = secondRear - secondFront;
		printf("QUEUE:%s \t FRONT:%d \t REAR:%d \t SIZE:%d\n", queue, secondFront, secondRear, size);
		if(size == 0)
		{
			printf(" NO_CONTENT");
		}
		else
		{
			int i;
			for(i=secondFront; i<secondRear; i++)
			{
				printf("%d\t", array[i]);
			}
		}
		printf("\n");
	}
}

void readFile(FILE* file) {
    char command[MAX_SIZE];
    char key[MAX_SIZE];
    int value;
	
    while (fscanf(file, "%s %s %d", command, key, &value) != EOF) {		// read the input file command = queue, enqueue, print
		if (strcmp(command, "ENQUEUE") == 0)							// key = first, second
		{																
            enqueue(key, value);
        } 
		else if (strcmp(command, "DEQUEUE") == 0) 
		{
        	dequeue(key);
        } 
		else if (strcmp(command, "PRINT") == 0) 
		{
            print(key);
		}
    }
}

int main()
{
	FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("File error");
        return 1;
    }

    readFile(file);
    fclose(file);
	
	getch();
	return 0;
}
