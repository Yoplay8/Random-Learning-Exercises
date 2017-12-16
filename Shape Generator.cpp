/**************************************************************************************************

//                                      Created by Ty Ler 

**************************************************************************************************/

/**************************************************************************************************
// Program may be slighly altered in the future to help reduce redundancy. Ive added comments that
// help break my code down into parts with the intentions that these parts can be broken down into
// smaller functions that will help reduce redundacy or help make the program more legible.

// Note to self: Program will be altered for Sololearn as all of my functions dont seem to work in
//               this complier. While ill also output the users input as Sololearn does not show
//               what the user has typed.
**************************************************************************************************/


/**************************************************************************************************

//                                       Input Requirments


// Note: Sololearn seems to loop my code when invalid data is given. Ive implemented error catchs
//       to help prevent an infinte loop. If users would like to test invalid data you will be able
//       to add valid data after invlaid data as the code is reiterated from the point of failure
//       not from the begining of the program.

// 1. Select a shape using numbers.
//      1. Square
//      2. Rectangle
//      3. Triangle

// 2. Enter in the size of the shape.
//      1. Square range 1-38
//      2. Rectangle Width*Height | Width range 1-38 | Height range 1-45 Excluding the number used
//         for width.
//      3. Triangle base range 1-38
**************************************************************************************************/


#include <iostream>
#include <string>


using namespace std;


void Users_Order();
void Build_Square(const int);
void Build_Rectangle(const int, const int);
void Build_Triangle(const int);


/*******************************************************

// main - Calls a function for the users input of a shape.

*******************************************************/
int main()
{


	Users_Order();


	//system("Pause");// Pause the screen so I can see output.

	
	return 0;

}


/**************************************************************************************************

// Users_Order - Holds the size restrictions for shapes, gets the shape from the user, and enters
//               the funtion the will build the shape.

**************************************************************************************************/
void Users_Order()
{


	const int Max_Width = 38;// Max width of shapes.
	const int Max_Height = 45;// Max height of shapes.
	const int Array_Size = 3;// Max size of shapes array.
	string Shapes[Array_Size] = {"Square", "Rectangle", "Triangle"};// Shape options.


//********* Users_Order Part 1.0 Start *********


	cout << "Shape Options\n";
	

	int Shape_Num;// Holds users shape number.

	do
	{// Keep looping until the users puts in a vaild shape option.
        
        
		for (int Count = 0; Count < Array_Size; Count++)
		{// Display all shape options.


			cout << "  " << (Count + 1) << ". " << Shapes[Count] << endl;

		}

		
		cout << "\n\nEnter in the number of the shape you want: ";
		cin >> Shape_Num;
        cout << Shape_Num << endl;


		if (cin.fail())// Look to see if the user typed in a character or string instead of a number
			           // and prevent crashing if so.
		{


			cin.sync();// Discard unread characters in input buffer
			cin.clear();// Clear bad input flag
			return;// Continue;

		}


		//system("CLS");// Clear screen.

	} while (Shape_Num < 1 || Shape_Num > Array_Size);


//********* Users_Order Part 1.0 End *********


//********* Users_Order Part 2.0 Start *********


	Shape_Num--;// Lower the users number by one in order to pick the right shape in the Shapes array.

	switch (Shape_Num)
	{// Find the function that will build the users shape.


		case 0:
			Build_Square(Max_Width);
			break;
		case 1:
			Build_Rectangle(Max_Width, Max_Height);
			break;
		case 2:
			Build_Triangle(Max_Width);
			break;

	}


//********* Users_Order Part 2.0 End *********

}

/****************************************************************************

// Build_Square - Asks the user for the size of the square and displays the
//                results.

****************************************************************************/
void Build_Square(const int Max_Square)
{


	int Square_Size;// Hold users size of square.


//********* Build_Square Part 1.0 Start *********


	do
	{// Keep looping until the users puts in a vaild square size.


		cout << "\nEnter in the size of the square you want" << endl << "in the range of 1-" <<
			 Max_Square << ": ";
		cin >> Square_Size;
        cout << Square_Size << endl << endl;


		if (cin.fail())// Look to see if the user typed in a character or string instead of a number
			           // and prevent crashing if so.
		{


			cin.sync();// Discard unread characters in input buffer
			cin.clear();// Clear bad input flag
			return;// Continue;

		}


		//system("CLS");// Clear screen.

	} while (Square_Size < 1 || Square_Size > Max_Square);


//********* Build_Square Part 1.0 End *********


//********* Build_Square Part 2.0 Start *********


	for (int Count_1 = Square_Size; Count_1 > 0; Count_1--)
	{// Loop till square is done.


		for (int Count_2 = Square_Size; Count_2 > 0; Count_2--)
		{// Display squares row.


			cout << "* ";

		}


		cout << endl;

	}


//********* Build_Square Part 2.0 End *********

}

/*********************************************************************************

// Build_Rectangle - Asks the user for the size of the Rectangle and displays the
//                   results.

*********************************************************************************/
void Build_Rectangle(const int Max_X, const int Max_Y)
{


	int Rectangle_Width, Rectangle_Height;// Hold the width and height of the users rectangle.


//********* Build_Rectangle Part 1.1 Start *********


	do
	{// Keep looping until the users puts in a vaild rectangle (width) size.


		cout << "\nEnter in the width of the rectangle in the" << endl << "range of 1-" << Max_X
			 <<": ";
		cin >> Rectangle_Width;
        cout << Rectangle_Width << endl;


		if (cin.fail())// Look to see if the user typed in a character or string instead of a number
			           // and prevent crashing if so.
		{


			cin.sync();// Discard unread characters in input buffer
			cin.clear();// Clear bad input flag
			return;// Continue;

		}


		//system("CLS");// Clear screen.

	} while (Rectangle_Width < 1 || Rectangle_Width> Max_X);


//********* Build_Rectangle Part 1.1 End *********

//********* Build_Rectangle Part 1.2 Start *********
	do
	{// Keep looping until the users puts in a vaild rectangle (height) size.


		cout << "\nEnter in the height of the rectangle in the" << endl << "range of 1-" << Max_Y
			 << " | Excluding number " << Rectangle_Width << ": ";
		cin >> Rectangle_Height;
        cout << Rectangle_Height << endl << endl;


		if (cin.fail())// Look to see if the user typed in a character or string instead of a number
			           // and prevent crashing if so.
		{


			cin.sync();// Discard unread characters in input buffer
			cin.clear();// Clear bad input flag
			return;// Continue;

		}


		//system("CLS");// Clear screen.

	} while (Rectangle_Height < 1 || Rectangle_Height > Max_Y || Rectangle_Height == Rectangle_Width);


//********* Build_Rectangle Part 1.2 End *********


//********* Build_Rectangle Part 2.0 Start *********


	for (int Count_1 = Rectangle_Height; Count_1 > 0; Count_1--)
	{// Loop till rectangle is done.


		for (int Count_2 = Rectangle_Width; Count_2 > 0; Count_2--)
		{// Display rectangles row.


			cout << "* ";

		}


		cout << endl;

	}
	

//********* Build_Rectangle Part 2.0 End *********

}

/*******************************************************************************

// Build_Triangle - Asks the user for the size of the triangle and displays the
//                  results.

*******************************************************************************/
void Build_Triangle(const int Max_Base)
{


	int Triangle_Size;// Hold the size of users triangle.


//********* Build_Triangle Part 1.0 Start *********


	do
	{// Keep looping until the users puts in a vaild triangle size.


		cout << "\nEnter in the size of the base of the" << endl
			 << "triangle you want in the range of 1-" << Max_Base << ": ";
		cin >> Triangle_Size;
        cout << Triangle_Size << endl << endl;


		if (cin.fail())// Look to see if the user typed in a character or string instead of a number
			           // and prevent crashing if so.
		{


			cin.sync();// Discard unread characters in input buffer
			cin.clear();// Clear bad input flag
			return;// Continue;

		}


		//system("CLS");// Clear screen.

	} while (Triangle_Size < 1 || Triangle_Size > Max_Base);


//********* Build_Triangle Part 1.0 End *********


//********* Build_Triangle Part 2.1 Start *********


	int Space_Count = (Triangle_Size / 2)*2;// Hold the number of spaces in triangle.
	int Dot_Count = 1;// Hold the number of dots in triangle.
	bool Flag = true;// Used to help create the first line in even based numbered triagnles.


	if ((Triangle_Size % 2) == 0)
	{// Helps to create the top line on even based numbered triangles.
		
		
		Flag = false;
		
		Space_Count--;
		
	}


//********* Build_Triangle Part 2.1 End *********

//********* Build_Triangle Part 2.2 Start *********


	for (; Dot_Count <= Triangle_Size; Space_Count -= 2, Dot_Count += 2)
	{// Loop until triangle is done.


		for (int Count_2 = Space_Count; Count_2 > 0; Count_2--)
		{// Display spaces.


			cout << " ";

		}

		for (int Count_3 = Dot_Count; Count_3 > 0; Count_3--)
		{// Display dots.

			 
			cout << "* ";

		}


		cout << endl;


		if (!Flag)	
		{// Flag will be reset once the first line has been created.


			Flag = true;
			Dot_Count--;
			Space_Count++;

		}

	}


//********* Build_Triangle Part 2.2 End *********

}