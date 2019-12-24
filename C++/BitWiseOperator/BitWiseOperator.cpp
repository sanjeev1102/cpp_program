

#include<iostream>
using namespace std;

namespace nm01
{
	// 1. Check if a number is even or Odd using bitwise & operator
	//===============================
	/*
	int main() {
		int n;
		cout << "Enter number to check Even or Odd" << "\n";
		cin >> n;

		if (n & 1) {
			cout << n << "  is an Odd Number" << "\n";
		}
		else
		{
			cout << n << "  is an Even Number" << "\n";
		}

		return 0;
	} */
	//===================================================

	/*
	class PopupWindow
	{
	public:
		  int YES = 1;
		  int NO  = 2;
		  int OKAY  = 4;
		  int CANCEL  = 8;

	 void showPopup(int buttons)
		{
		 cout << "Calling showpopup fucntion......." << endl;
			if (buttons & YES)
			{
				 cout <<  " Add YES button" << "\n";
			}

			if (buttons & NO)
			{
				cout << " Add NO button" << "\n";
			}
			if (buttons & CANCEL)
			{
				cout << " Add CANCEL button" << "\n";
			}
			if (buttons & OKAY)
			{
				cout << " Add OKAY button" << "\n";
			}
		}
	};

	int main() {

		PopupWindow popup;
		//popup.showPopup(popup.YES | popup.NO | popup.CANCEL);
		//popup.showPopup(popup.YES | popup.NO );
		//popup.showPopup(popup.YES );
		//popup.showPopup(popup.YES | popup.NO | popup.CANCEL | popup.OKAY);     // here in this case pass value for button is  ( ( 01 | 10 | 100 | 1000) = 1111 ) and hence all four button will be displayed
		popup.showPopup(popup.CANCEL | popup.NO | popup.OKAY);
		return 0;
	}
	*/

	/* Swap two nibbles in a byte
	A nibble is a four - bit aggregation, or half an octet.There are two nibbles in a byte.
	Given a byte, swap the two nibbles in it.For example 100 is be represented as 01100100 in a byte(or 8 bits).The two nibbles are(0110) and (0100).If we swap the two nibbles, we get 01000110 which is 70 in decimal. */
	// C++ program to swap two
	// nibbles in a byte
	//#include <bits/stdc++.h>
	using namespace std;

	int swapNibbles(int x)
	{
		return ((x & 0x0F) << 4 | (x & 0xF0) >> 4);
	}

	// Driver code
	int main()
	{
		int x = 128;
		cout << swapNibbles(x);
		return 0;
	}
}
