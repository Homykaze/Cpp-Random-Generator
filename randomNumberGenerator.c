#include <stdio.h>
#include <stdlib.h>

/* Prime number of reference for pseudo-random number generation.. */
/* It is used to generate pseudo-random numbers in the range [0, 210] inclusive. */ 
#define PRIME_NUMBER 211

/* Linked list of 100 000 elements, it is used to store statistics about how many times a certain number is generated. */
struct values {
    int n;
    int value;

    struct values *next;
};

/* Pseudo-random number generating algorithm. */
int randomize(struct values *p_list, int n);
/* Pseudo-random number getter. */
int getNumber(struct values *p_list, int n);
/* Linked-list expander. */
struct values *addNew(struct values *p_list, int k);

int main()
{
	/* Linked list to store data. */
    struct values *p_list = NULL;
	/* Statistics about frequencies of 100 000 cases of random-number generation is stored in this array. */
    int statistics[PRIME_NUMBER];
	/* Input. */
    int n;

	/* Initial number of cases is 0 (nothing was generated yet, i.e. 0 to every case). */
    for (int i = 0; i < PRIME_NUMBER; i++)
    {
        statistics[i] = 0;
    }
	/* Initialization of the linked list. */
    for (int i = 0; i < 100000; i++)
    {
		/* Index. */
        int k = i;
		/* Adding elements with the values we need to the list. */
        p_list = addNew(p_list, k);
    }
	/* Getting statistics here. */
    struct values *curr = p_list;
    while (curr != NULL)
    {
		/* We are storing the number of generated instances in indices of the array with the needed statistics. */
        statistics[curr->value]++;
        curr = curr->next;
    }

	/* Displaying statistics. */
    printf("Using prime number 211 for random-number generation in range [0, 210] inclusive.\n");
    printf("Out of 100 000 cases the following statistics is gotten:\n");
    for (int i = 0; i < PRIME_NUMBER; i++)
    {
        printf("Number %d is randomized %d times.\n", i, statistics[i]);
    }
	/* Loop to test user's inputs and outputs (outputs will always be the same to the same inputs). */
    int input;
    do {
        printf("Enter -1 to exit. Try your own input to generate a number: ");
        scanf("%d", &input);
        printf("%d\n", getNumber(p_list, input));
    } while (input != -1);

    return 0;
}

/* We add numbers to the list and generate a random value right here. */
struct values *addNew(struct values *p_list, int k)
{
	/* Memory allocation. */
    struct values *p_item = (struct values *)malloc(sizeof(struct values));

	/* Filling in the data structure. */
    p_item->n = k;
	/* Pseudo-random number generation. */
    p_item->value = randomize(p_list, k);     

	/* The newly allocated node is the first in the list. */
    p_item->next = p_list;
    p_list = p_item;
    return p_list;
}

/* Pseudo-random number getter. */
int getNumber(struct values *p_list, int n)
{
	/* Simple case, can be modified, the number of OR cases depends on the depth of recursion.. */
    if (n == 1 || n == 2 || n == 3 || n == 0)
    {
        return 1;
    }
    else
    {
		/* Iterate over the list to find the needed number. */
        struct values *curr = p_list;
        while (curr != NULL)
        {
            if (n == curr->n)
            {
                return curr->value;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    return 1;
}

/* Pseudo-random number generating algorithm. */
int randomize(struct values *p_list, int n)
{
    int result;
    int var_one;
    int var_two;
    int var_three;
    int var_four;

	/* Base cases. */
    if (n == 1 || n == 2 || n == 3 || n == 0)
    {
        return 1;
    }
    else
    {
		/* The result is based on remainder of four previous values added together and divided by prime number 211. */
        var_one = getNumber(p_list, n - 1);
        var_two = getNumber(p_list, n - 2);
        var_three = getNumber(p_list, n - 3);
        var_four = getNumber(p_list, n - 4);
        result = (var_one + var_two + var_three + var_four) % PRIME_NUMBER;
        return result;
    }
}