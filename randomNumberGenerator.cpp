#include <iostream>
// Prime number of reference
#define PRIME_NUMBER 211
using namespace std;

//Linked list of 100 000 elements, it is used to store statistics about how many times a certain number is generated
struct values
{
	int n;							//Index of the element
	int value;						//Value of a pesudo-random number generated based on the given index

	values *next;					//pointer to the next element in the list
};

//Pseudo-random number generating algorithm
int randomize(values *p_list, int n);
//Pseudo-random number getter
int getNumber(values *p_list, int n);
//Linked-list expander
values *addNew(values *p_list, int k);

int main()
{
	values *p_list = NULL;			//Linked list to store data
	int statistics[PRIME_NUMBER];	//Statistics about frequencies of 100 000 cases of random-number generation is stored in this array
	int n;							//Input

	//Initial number of cases is 0 (nothing was generated yet, i.e. 0 to every case)
	for (int i = 0; i < PRIME_NUMBER; i++)
	{
		statistics[i] = 0;
	}
	//Initialization of the linked list
	for (int i = 0; i < 100000; i++)
	{
		int k = i;					//Index
		p_list = addNew(p_list, k); //Adding elements with the values we need to the list
	}
	//Getting statistics here
	values *curr = p_list;
	while (curr != NULL)
	{
        //We are storing the number of generated instances in indeces of the array with the needed statistics
		statistics[curr->value]++;
		curr = curr->next;
	}

	//Displaying statistics
    cout << "Using prime number 211 for random-number generation in range [0, 210] inclusive.\n";
	cout << "Out of 100 000 cases the following statistics is gotten:\n";
	for (int i = 0; i < PRIME_NUMBER; i++)
	{
		cout << "Number " << i << " is randomized " << statistics[i] << " times.\n";
	}
	// Loop to test user's inputs and outputs (outputs will always be the sam to the same inputs)
	int input;
	do {
		cout << "Enter -1 to exit. Try your own input to generate a number: ";
		cin >> input;
		cout << getNumber(p_list, input) << endl;
	} while (input != -1);
}

//We add numbers to the list and generate a random value right here
values *addNew(values *p_list, int k)
{
	//Memory allocation
	values *p_item = new values;

	//Filling in the data structure
	p_item->n = k;
	p_item->value = randomize(p_list, k);	 
	//^Pseudo-andom number generation^

	//The newly allocated node is the first in the list
	p_item->next = p_list;
	p_list = p_item;
	return p_list;
}

//Pseudo-random number getter
int getNumber(values *p_list, int n)
{
    //Simple case
	if (n == 1 || n == 2 || n == 3 || n == 0)
	{
		return 1;
	}
	else
	{
        //Iterate over the list to find the needed number
		values *curr = p_list;
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

//Pseudo-random number generating algorithm
int randomize(values *p_list, int n)
{
	int result;
	int var_one;
	int var_two;
	int var_three;
	int var_four;

	//Base cases
	if (n == 1 || n == 2 || n == 3 || n == 0)
	{
		return 1;
	}
	else
	{
        //The result is based on remainder of four previous values added together and divided by prime number 211
		var_one = getNumber(p_list, n - 1);
		var_two = getNumber(p_list, n - 2);
		var_three = getNumber(p_list, n - 3);
		var_four = getNumber(p_list, n - 4);
		result = (var_one + var_two + var_three + var_four) % PRIME_NUMBER;
		return result;
	}
}