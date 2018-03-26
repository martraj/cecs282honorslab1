// MARIEL TRAJANO
// CECS 282 HONORS LAB ASSIGNMENT 1
// MAGIC SQUARE

#include <iostream>
#include <sstream>
using namespace std;

string createSquare(int **square, const int size);
string intToString (int a);

// creates a magic square of a given size, returns the square as a string
string createSquare(int **square, const int size)
{
	if(size%2 == 0) { return "Cannot create a square of even numbered size."; }
	else
	{
		square = new int*[size];
		string str = "";
		
		// initializing all elements in 2d array to 0
		for (int i = 0; i < size; i++)
		{
			square[i] = new int[size];
			for (int j = 0; j < size; j++){
				square[i][j] = 0;
			}
		}

		int currRow = size-1; // bottom row
		int currCol = size/2; // middle column
				
		for(int num = 1; num <= size*size; num++)
		{
			square[currRow][currCol] = num; // sets the current row & col to the number
			
			int nextRow = (currRow + 1) % size;
			int nextCol = (currCol + 1) % size;
			
			if(square[nextRow][nextCol] != 0) // if the next row is filled, go to the one above
			{
				currRow -= 1;
			}
			else // else, go to next row & col
			{
				currRow = nextRow;
				currCol = nextCol;
			}
		}
		
		// creates a string of the matrix
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++){
				str += intToString(square[i][j]) + "\t ";
			}
			str += "\n" ;
		}

		return str;
	}
	
}

// converts integer to string
string intToString (int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}



int main()
{
	int** newsq;
	int n = 0;
	cout << "Enter an odd number: ";
	cin >> n;
	while(n != 0)
	{
		cout << createSquare(newsq, n);	
		cout << "\nEnter another number or 0 to quit: ";
		cin >> n;	
	}

	return 0;
}
