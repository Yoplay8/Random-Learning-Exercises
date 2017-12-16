#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


void Get_Users_Input();
void Create_Matrix(int, int);
void Display_Matrix(int **&, int, int);


int main()
{


	Get_Users_Input();


	system("Pause");


	return 0;
}


void Get_Users_Input()
{


	int Matrix_Width, Matrix_Height;

	cout << "Enter in the width of the matrix: ";
	cin >> Matrix_Width;
	cout << Matrix_Width << endl << endl;

	cout << "Enter in the height of the matrix: ";
	cin >> Matrix_Height;
	cout << Matrix_Height << endl << endl;


	Create_Matrix(Matrix_Width, Matrix_Height);

}

void Create_Matrix(int Width, int Height)
{


	int Top = 0, Left = 0, Bottom = Height, Right = Width;
	int **pMatrix_Array = NULL;
	
	try
	{


		pMatrix_Array = new int*[Height];

		for (int Count = 0; Count < Height; Count++)
		{


			pMatrix_Array[Count] = new int[Width];

		}

	}
	catch (...)
	{


		cout << "Pick a smaller matrix size. Could not create matrix.";

	}


	int Direction_In_Loop = 0;

	if (Width >= Height)
		Direction_In_Loop = ((Height * 2) - 1);
	else
		Direction_In_Loop = (Width * 2);


	int Matrix_Counter = 1;

	while (Direction_In_Loop > 0)
	{

		
		

		for (int Count = Left; Count < Right; Count++)
		{


			pMatrix_Array[Top][Count] = Matrix_Counter;
			Matrix_Counter++;

		}

		Top++;
		Right--;
		Direction_In_Loop--;


		if (Direction_In_Loop == 0)
			break;


		for (int Count = Top; Count < Bottom; Count++)
		{


			pMatrix_Array[Count][Right] = Matrix_Counter;
			Matrix_Counter++;

		}

		Direction_In_Loop--;
		

		if (Direction_In_Loop == 0)
			break;


		Bottom--;

		for (int Count = Right - 1; Count >= Left; Count--)
		{


			pMatrix_Array[Bottom][Count] = Matrix_Counter;
			Matrix_Counter++;

		}

		Direction_In_Loop--;


		if (Direction_In_Loop == 0)
			break;


		for (int Count = (Bottom - 1); Count >= Top; Count--)
		{


			pMatrix_Array[Count][Left] = Matrix_Counter;
			Matrix_Counter++;

		}

		Left++;
		Direction_In_Loop--;

	}


	Display_Matrix(pMatrix_Array, Width, Height);

}

void Display_Matrix(int **&Matrix, int Array_X, int Array_Y)
{


	int All_Nums = Array_X * Array_Y;
	int Set_Width = 1;

	for (int Mult_Num = 1; (All_Nums - Mult_Num) >= 0; Mult_Num *= 10)
		Set_Width += 1;

	for (int Count_1 = 0; Count_1 < Array_Y; Count_1++)
	{


		for (int Count_2 = 0; Count_2 < Array_X; Count_2++)
		{


			cout << setw(Set_Width) << Matrix[Count_1][Count_2];

		}

		cout << endl;

	}

}