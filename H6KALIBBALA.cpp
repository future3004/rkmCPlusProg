/*
                        Program No.		: Kalibbala_Richard_H6.cpp
	                    Programmer		: Richard Kalibbala
	                	Course/Section	: ELET 2300?04/17955 
		                Instructor		: Dr. F. Attarzadeh
	                    Date Assigned	: 11/07/2017
	                    Date Modified	: 11/15/2017
                     	Due Date		: 11/16/2017
	                    Compiler		: Microsoft Visual Studio Enterprise 2015
	                    Environment		: Console Applications
                     	Operating System: Windows 10

*/
/*
                                       Problem Statement
    This is a menu driven C++ program that uses user-defined functions, arrays, and a random number generator function to fill an array with
	values. Upon execution of the program, the menu will be displayed in the middle of the screen. The program prompts the user to choose
	the number of elements to examine from the array. The maximum number of elements in the array are 30. Then the user is prompted for the 
	range of values of type double to fill the array. The largest number is found out of the array values and the its frequency. The program
	then displays the array with values, the largest number, and its frequency.


*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>

using namespace std;

void help(void);                                                   // function prototypes
void largest(double s[], int maxSize);
int sizeOfArray(void);
double randArrayValues(double K, double Z);                         // random value generator prototype function
double findLargest(double y[], int x);
int frequency(double m[], double biggest, int userSize);
void display(double progArray[], double q, int freqValue, int userChoiceSize);



int main() {

	const int SIZE = 30;

	double myArray[SIZE];


	char menuSelection;

	do
	{

		cout << setw(75) << "Help          Largest          Quit" << endl <<endl;
		cout << "Enter a menu selection: ";
		cin >> menuSelection;

		// spacing
		cout << endl;

		switch (menuSelection)
		{

		           case 'H':
		           case 'h':
		           {

					 // function help call
					   help();


					   break;
		           }

				   case 'L':
				   case 'l':
				   {
					   int userArraySize;                  // variable to store user's array size to examine
					   double a, b;                        // range values variables

					   largest(myArray, SIZE);

					   // program spacing
					   cout << endl;

					  userArraySize = sizeOfArray();              // returns the user's array size to examine

					  // user selects their desired range of values to fill the array
					  cout << "Enter the Range of double( eg 25.5) to fill the array with values: \n"
						  << setw(15) << "Range from: ";
					  cin >> a;

					  cout << endl;
					  cout << setw(10) << "To: ";
					  cin >> b;

					  cout << endl;


					  //fill the array with random generated values
					  for (int i = 0; i < userArraySize; i++) {

						  myArray[i] = randArrayValues(a, b);

						
					  }

					  // findLargest function call; returns double largest number
					  double largestNumb = findLargest(myArray, userArraySize);

					 
					 // invoking the frequency function; returns int frequency
					 int freqLargestNum = frequency(myArray, largestNumb, userArraySize);

					 //fuction display call to show the results
					 display(myArray, largestNumb, freqLargestNum, userArraySize);



					   break;
				   }

				   case 'Q':
				   case 'q':
				   {

					   // clears the screen 
					   system("CLS");

					   break;
				   }


		          default:
				  {
					  // ERROR: user chose the wrong Menu selection, display Menu again
					  cout << setw(10) << " ERROR\n";
					  cout << " Your selection is NOT part of the Menu: \n";

					  cout << endl;
					  system("PAUSE");

					  break;
				  }


			
		}




	} while (menuSelection != 'Q' && menuSelection != 'q');




	return 0;                       // end of function Main();
}

// Fuction Definitions
// Help function definition
void help(void) {

	cout << setw(25) << "HELP SCREEN" << endl;

   cout << "The Menu selections are: \n";
   cout << "H or h ----------------- for Help\n"
		<< "L or l ----------------- for Largest\n"
		<< "Q or q ----------------- for Quit\n" << endl;

   cout << "Help : displays this information." << endl <<endl;
   cout << "This program uses an Array of 30 elements of type Double; \n"
	   << "finds the largest number in the Array and the number of times it appears(frequency).\n"
	   << "The program then displays the desired array elements, largest number and its Frequency of occurrence." << endl <<endl;

   cout << "Largest : prompts you to select the Number of elements for the Array to be examined. MAXIMUM NUMBER OF ELEMENTS IS 30!!\n"
	   << "        : then select the Range of Double Values desired to fill the Array. \n"
	   << " Number of elements for the Array ...........are of type Integer ( 0 > x < 30 ) \n "
	   << "Range of Values to fill the Array ..........are of type Double (eg 23.45, 100.0) " << endl <<endl;

   cout << "Quit : will clear and terminate the progam." << endl << endl;

   system("PAUSE");

   system("CLS");

	

}

// largest() function definition
void largest(double s[], int maxSize) {


	cout << "The specified Array in this program is of maximum SIZE : " << maxSize << endl;


}
// sizeOfarray() function definition
int sizeOfArray(void) {

	int originalSize = 30;
	int userNumber;


		cout << "Enter the desired number of elements in Array to be examined: " << endl;
		cin >> userNumber;

		if (userNumber > 0 && userNumber < 30) {          // check to see if choice is VALID

			return userNumber;
		}
		else
		{

			// user chose wrong number of elements in array; will use default size
			cout << endl;
			cout << "ERROR Invalid number chose; maximum Size = 30, Maximum Size will be used.\n";

			return originalSize;
		}
	


}

// random values generator function definition
double randArrayValues(double K, double Z) {


	return K + (rand() / (RAND_MAX / (Z - K)));
}

// findLargest() function definition
double findLargest(double y[], int x) {

	double largestNum = 0.0;


	for (int i = 0; i < x; i++) {

	
		if (y[i] >= largestNum) {

			largestNum = y[i];

		}


	}


	return largestNum;

}

// frequency() function definition; returns int frequency
int frequency(double m[], double biggest, int userSize) {

	int freqCounter = 0;

	for (int j = 0; j < userSize; j++) {      // loops through the array

		if (m[j] == biggest) {           // number of times largest no. appears

			freqCounter++;         // increment the frequecy counter
		}

	}


	// return the frequency
	return freqCounter;
}



// display() function to show the results
void display(double progArray[], double q, int freqValue, int userChoiceSize) {


	// for loop to display the array elements
	for (int r = 0; r < userChoiceSize; r++) {

		cout << "myArray[" << r << "]" << " = " << fixed << setprecision(2) << progArray[r] << endl;

	}

	// display the largest no. and its frequency
	cout << endl;
	cout << "Largest no. = " << fixed << setprecision(2) << q << setw(20) <<"Frequency = " << freqValue << endl;

	cout << endl << endl;
	cout << setw(105) << "Strike any key to continue..." << endl << flush;      

	cout << endl;
	system("PAUSE");

	system("CLS");         // enter key to clear screen

	                                    

}

// SAMPLE RUNS

/*
            Run 1
                                                 Help          Largest          Quit

Enter a menu selection: l

The specified Array in this program is of maximum SIZE : 30

Enter the desired number of elements in Array to be examined:
10
Enter the Range of double( eg 25.5) to fill the array with values:
   Range from: 20.5

      To: 95.6

myArray[0] = 20.59
myArray[1] = 62.83
myArray[2] = 35.02
myArray[3] = 81.24
myArray[4] = 64.43
myArray[5] = 56.54
myArray[6] = 46.81
myArray[7] = 87.79
myArray[8] = 82.30
myArray[9] = 76.57

Largest no. = 87.79        Frequency = 1


                                                                       Strike any key to continue...

Press any key to continue . . .



                     Run 2
 
                                            Help          Largest          Quit

 Enter a menu selection: l

 The specified Array in this program is of maximum SIZE : 30

 Enter the desired number of elements in Array to be examined:
 20
 Enter the Range of double( eg 25.5) to fill the array with values:
 Range from: 9.4

 To: 200.4

 myArray[0] = 10.29
 myArray[1] = 11.10
 myArray[2] = 81.58
 myArray[3] = 110.95
 myArray[4] = 118.50
 myArray[5] = 124.34
 myArray[6] = 125.37
 myArray[7] = 41.15
 myArray[8] = 136.04
 myArray[9] = 95.50
 myArray[10] = 76.66
 myArray[11] = 20.29
 myArray[12] = 125.47
 myArray[13] = 159.01
 myArray[14] = 162.70
 myArray[15] = 108.70
 myArray[16] = 67.07
 myArray[17] = 176.71
 myArray[18] = 148.20
 myArray[19] = 191.98

 Largest no. = 191.98        Frequency = 1


                                                                                   Strike any key to continue...

 Press any key to continue . . .





*/






















