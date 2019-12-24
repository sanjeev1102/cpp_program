

/*
 * C++ Program to Implement Singly Linked List: all operation ..
 */

#include<iostream>
#include<cstdio>
using namespace std;

namespace nm01
{
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
		void Selection_sort();
		void Bubble_sort();
		void delete_pos();
		void update();
		void search();
		void reverse();
		void display();
		void Insertion_sort();
		//void Insertion_sort();

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
			cout << "4.Sort Link List with selection sort algorithm.." << endl;
			cout << "5.Delete a Particular Node" << endl;
			cout << "6.Update Node Value" << endl;
			cout << "7.Search Element" << endl;
			cout << "8.Display Linked List" << endl;
			cout << "9.Reverse Linked List " << endl;
			cout << "10. Sort Link List with Bubble sort algorithm.." << endl;
			cout << "11. Sort Link List with Insertion sort algorithm.." << endl;
			//cout << "12. Sort Link List with Bubble sort algorithm.." << endl;
			cout << "0.Exit " << endl;
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
				cout << "Sort Link List with selection sort Algorithm: " << endl;
				sl.Selection_sort();
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
				cout << "Sort Link List with Bubble sort Algrothim: " << endl;
				sl.Bubble_sort();
				cout << endl;
				break;
			case 11:
				cout << "Sort Link List with Insertion sort Algorithm: " << endl;
				sl.Insertion_sort();
				cout << endl;
				break;
			case 12:
				cout << "Sort Link List with Insertion sort Algorithm: " << endl;
				//sl.Insertion_sort();
				cout << endl;
				break;
			case 0:
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
		node* temp, * s;
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
		node* temp, * s, * ptr;

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

	How Selection Sort Works?
	Following are the steps involved in selection sort(for sorting a given array in ascending order):

	Starting from the first element, we search the smallest element in the array, and replace it with the element in the first position.
	We then move on to the second position, and look for smallest element present in the subarray, starting from index 1, till the last index.
	We replace the element at the second position in the original array, or we can say at the first position in the subarray, with the second smallest element.
	This is repeated, until the array is completely sorted.


	 */
	void single_llist::Selection_sort()
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

	  Working Bubble sort implementation..
	  */

	  /* Although the below logic will sort an unsorted array, still the above algorithm is not efficient because as per the above logic,
	  the outer for loop will keep on executing for no of iterations (as many no of elements) even if the array gets sorted after the second iteration.
	  So, we can clearly optimize our algorithm.

	  Optimized Bubble Sort Algorithm
	  To optimize our bubble sort algorithm, we can introduce a flag to monitor whether elements are getting swapped inside the inner for loop

	  Hence, in the inner for loop, we check whether swapping of elements is taking place or not, everytime.

	  If for a particular iteration, no swapping took place, it means the array has been sorted and we can jump out of the for loop, instead of executing all the iterations.
	  */

	void single_llist::Bubble_sort()
	{
		node* ptr1, * ptr2, * s;
		int value;

		if (start == NULL)
		{
			cout << "The List is empty" << endl;
			return;
		}

		ptr1 = start;

		while (ptr1 != NULL)
		{
			ptr2 = start;
			int flag = 0;
			for (s = ptr2->next; s != NULL; s = s->next)
			{
				// introducing a flag to monitor swapping for optimizeing purposeas mentioned above in comment section..
				//int flag = 0;

				if (ptr2->info > s->info)
				{
					value = ptr2->info;
					ptr2->info = s->info;
					s->info = value;
					// if swapping happens update flag to 1    for optimization code
					flag = 1;
				}
				ptr2 = ptr2->next;
			}
			// if value of flag is zero after all the iterations of inner loop
			// then break out
			if (!flag)
			{
				break;
			}
			ptr1 = ptr1->next;
			single_llist::display();
		}
	}

	/*
	Insertion Sort Algorithm  Not working yet:

	*/

	void single_llist::Insertion_sort()
	{
		node* ptr1, * ptr2, * s;
		int value;

		if (start == NULL)
		{
			cout << "The List is empty" << endl;
			return;
		}

		ptr1 = start;

		while (ptr1 != NULL)
		{
			ptr2 = start;
			for (s = ptr2->next; s != NULL; s = s->next)
			{

				if (ptr2->info > s->info)
				{
					value = ptr2->info;
					ptr2->info = s->info;
					s->info = value;

				}
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
			single_llist::display();
		}
	}


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

}
