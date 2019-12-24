C++ Programs..

#include<conio.h>
#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;


/* 
1. program to check whether two strings are anagram ofeach other   

: link: https://codescracker.com/cpp/program/cpp-anagram-program.htm
Here, fist we have to check the length of both the string, if length will be equal then further proceed else print the message for unequal length. 
Since to check for the anagram, the two string must having same length. Now we compare first character of first string to all the character of second string one by one,
then compare second character of first string to all the character of second string one by one, then compare third character of first string to all the character of second string one by one, 
and so on. When comparing, if any of the character of the first string will match to the character of second string, then we initialize 1 to the found, and exit the loop
and if there will no match found for any character, then 1 will not initialize to the found. So, found will be equal to 0, so that after exiting the inner loop, on checking "if(found==0)",
it becomes true and 1 will be initialize to not_found and exit the outer loop.	Now after exiting or completing the outer loop, we have to check whether not_found will be equal to 1 or 0.
If not_found will be equal to 1, then strings are not anagram and if not_found will be equal to 0 then strings are anagram.

*/


int main()
{
	
	char str1[20], str2[20];
	int len, len1, len2, i, j, found = 0, not_found = 0;
	cout << "Enter first string :";
	cin >> str1;
	cout << "Enter second string :";
	cin>>str2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 == len2)
	{
		len = len1;
		for (i = 0; i < len; i++)
		{
			found = 0;
			for (j = 0; j < len; j++)
			{
				if (str1[i] == str2[j])
				{
					found = 1;
					break;
				}
			}
			if (found == 0)
			{
				not_found = 1;
				break;
			}
		}
		if (not_found == 1)
		{
			cout << "Strings are not Anagram to each other";
		}
		else
		{
			cout << "Strings are Anagram";
		}
	}
	else
	{
		cout << "Two string must have same number of character to be Anagram";
	}
	
	return 0;
}

//==============================================================================

2. C++ Program To Implement Singly Linked List
This C++ Program Implements Singly Linked List.
Here is source code of the C++ Program to Implement Singly Linked List. The C++ program is successfully compiled and run on a Linux system. The program output is also shown below.

/*
 * C++ Program to Implement Singly Linked List
 */


/*
 * C++ Program to Implement Singly Linked List: all operation ..
 */

#include<iostream>
#include<cstdio>
//#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
/* 
*/
struct node
{
	int info;
	node* next;
}*start;


class single_llist
{
public:
	node* create_node(int);
	void insert_begin();
	void insert_last();
	void insert_pos();
	void sort();
	void delete_pos();
	void update();
	void search();
	void reverse();
	void display();

	single_llist() {

		start = NULL;
	}

	~single_llist() {

	}
};

/*
 * Main :contains menu
 */
int main()
{
	int choice;// nodes, element, position, i;
	single_llist sl;
	start = NULL;
	while (1)
	{
		cout << endl << "---------------------------------" << endl;
		cout << endl << "Operations on singly linked list" << endl;
		cout << endl << "---------------------------------" << endl;
		cout << "1.Insert Node at beginning" << endl;
		cout << "2.Insert node at last" << endl;
		cout << "3.Insert node at position" << endl;
		cout << "4.Sort Link List" << endl;
		cout << "5.Delete a Particular Node" << endl;
		cout << "6.Update Node Value" << endl;
		cout << "7.Search Element" << endl;
		cout << "8.Display Linked List" << endl;
		cout << "9.Reverse Linked List " << endl;

		cout << "10.Exit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Inserting Node at Beginning: " << endl;
			sl.insert_begin();
			cout << endl;
			break;
		case 2:
			cout << "Inserting Node at Last: " << endl;
			sl.insert_last();
			cout << endl;
			break;
		case 3:
			cout << "Inserting Node at a given position:" << endl;
			sl.insert_pos();
			cout << endl;
			break;
		case 4:
			cout << "Sort Link List: " << endl;
			sl.sort();
			cout << endl;
			break;
		case 5:
			cout << "Delete a particular node: " << endl;
			sl.delete_pos();
			break;
		case 6:
			cout << "Update Node Value:" << endl;
			sl.update();
			cout << endl;
			break;
		case 7:
			cout << "Search element in Link List: " << endl;
			sl.search();
			cout << endl;
			break;

		case 8:
			cout << "Display elements of link list" << endl;
			sl.display();
			cout << endl;
			break;
		case 9:
			cout << "Reverse elements of Link List" << endl;
			sl.reverse();
			cout << endl;
			break;
		case 10:
			cout << "Exiting..." << endl;
			exit(1);
			break;
		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0;
}


/*
 * Creating Node
 */
node* single_llist::create_node(int value)
{
	node* temp;
	temp = new node;
	if (temp == NULL)
	{
		cout << "Memory not allocated " << endl;
		return 0;
	}
	else
	{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}

/*
 * Inserting element in beginning
 */
void single_llist::insert_begin()
{
	int value;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	node* temp, * p;
	temp = create_node(value);
	if (start == NULL)
	{
		cout << " Start iss NULL means linklist is empty hence creating first note.." << endl;
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;
	}
	cout << "Element Inserted at beginning" << endl;
}

/*
 * Inserting Node at last
 */
void single_llist::insert_last()
{
	int value;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	node* temp, *s;
	temp = create_node(value);

	if (start == NULL)
	{
		cout << " Start iss NULL means linklist is empty hence creating first note.." << endl;
		start = temp;
		start->next = NULL;
	}
	else
	{
		s = start;
		while (s->next != NULL)
		{
			s = s->next;
		}

		temp->next = NULL;
		s->next = temp;
	}
	cout << "Element Inserted at last" << endl;
}

void single_llist::insert_pos()
{
	int value, pos, counter = 0;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	node* temp, *s, *ptr;

	temp = create_node(value);
	cout << "Enter the postion at which node to be inserted: ";
	cin >> pos;

	int i;
	s = start;
	while (s != NULL)
	{
		s = s->next;
		counter++;
	}
	if (pos == 1)
	{
		if (start == NULL)
		{
			start = temp;
			start->next = NULL;
		}
		else
		{
			ptr = start;
			start = temp;
			start->next = ptr;
		}
	}
	else if (pos > 1 && pos <= counter)
	{
		s = start;
		ptr = start;

		for (i = 1; i < pos; i++)
		{
			ptr = s;
			s = s->next;
		}
		ptr->next = temp;
		temp->next = s;
	}
	else
	{
		cout << "Positon out of range" << endl;
	}
}

/*
 * Sorting Link List
 Selection Sort Algorithm : below implementation is selection sort
 Selection sort is conceptually the most simplest sorting algorithm. This algorithm will first find the smallest element in the array
 and swap it with the element in the first position, then it will find the second smallest element and swap it with the element in the
 second position, and it will keep on doing this until the entire array is sorted.
It is called selection sort because it repeatedly selects the next-smallest element and swaps it into the right place.

 */
void single_llist::sort()
{
	node* ptr, * s;
	int value;

	if (start == NULL)
	{
		cout << "The List is empty" << endl;
		return;
	}

	ptr = start;
	while (ptr != NULL)
	{
		for (s = ptr->next; s != NULL; s = s->next)
		{
			if (ptr->info > s->info)
			{
				value = ptr->info;
				ptr->info = s->info;
				s->info = value;
			}
		}
		ptr = ptr->next;
		single_llist::display();
	}
}

/* Bubble Sort Algorithm :  
  If the given array has to be sorted in ascending order, then bubble sort will start by comparing the first element of the array 
  with the second element, if the first element is greater than the second element, it will swap both the elements, 
  and then move on to compare the second and the third element, and so on.
  If we have total n elements, then we need to repeat this process for n-1 times. It is known as bubble sort.
  
  need to implement bubble short here
  */



  /*
   * Delete element at a given position
   */
void single_llist::delete_pos()
{
	int pos, i, counter = 0;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter the position of value to be deleted: ";
	cin >> pos;
	node* s, * ptr;
	s = start;
	if (pos == 1)
	{
		start = s->next;
	}
	else
	{
		while (s != NULL)
		{
			s = s->next;
			counter++;
		}
		if (pos > 1 && pos <= counter)
		{
			ptr = s = start;
			for (i = 1; i < pos; i++)
			{
				ptr = s;
				s = s->next;
			}
			ptr->next = s->next;
		}
		else
		{
			cout << "Position out of range" << endl;
			return;
		}
	}
	free(s);
	cout << "Element Deleted" << endl;
}


/*
 * Update a given Node
 */
void single_llist::update()
{
	int value, pos, i, counter = 0;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter the node postion to be updated: ";
	cin >> pos;
	cout << "Enter the new value: ";
	cin >> value;
	node* s, * ptr;
	s = ptr = start;
	if (pos == 1)
	{
		start->info = value;
	}
	else
	{
		while (ptr != NULL)
		{
			ptr = ptr->next;
			counter++;
		}
		if (pos > 1 && pos <= counter)
		{
			for (i = 0; i < pos - 1; i++)
			{
				if (s == NULL)
				{
					cout << "There are less than " << pos << " elements";
					return;
				}
				s = s->next;
			}
			s->info = value;
		}
		else
		{
			cout << "Position out of range" << endl;
			return;
		}
	}
	cout << "Node Updated" << endl;
}

/*
 * Searching an element
 */
void single_llist::search()
{
	int value, pos = 0;
	bool flag = false;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter the value to be searched: ";
	cin >> value;
	struct node* s;
	s = start;
	while (s != NULL)
	{
		pos++;
		if (s->info == value)
		{
			flag = true;
			cout << "Element " << value << " is found at position " << pos << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "Element " << value << " not found in the list" << endl;
}

/*
 * Reverse Link List
 */
void single_llist::reverse()
{
	node* ptr1, * ptr2, * ptr3;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	if (start->next == NULL)
	{
		return;
	}
	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	ptr1->next = NULL;
	ptr2->next = ptr1;
	while (ptr3 != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;
	}
	start = ptr2;
}

/*
 * Display Elements of a link list
 */
void single_llist::display()
{
	node* temp;
	if (start == NULL)
	{
		cout << "The List is Empty" << endl;
		return;
	}
	temp = start;
	cout << "Elements of list are: " << endl;
	while (temp != NULL)
	{
		cout << temp->info << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}