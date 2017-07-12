/*
 * sudoku.cpp
 *
 *  Created on: 24-Jun-2017
 *      Author: SONY
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>	//for function time and data-type time_t
#include <iomanip>	//for exit(0) to exit the program

using namespace std;

class sudoku
{
public:
	int row, col,
	 board[10][10];
	int col_copy=1, row_copy=1;	//used to store previous entry and used in case of repeated entry by user

	void genBoard();
	void displayBoard();
	void genRandomInt(int);
	void getData(char);
	void Verify();
};

void sudoku::genBoard()
{
	for(row=1; row<10; row++)
	{
		for(col=1; col<10; col++)
		{
			board[row][col] = 0;
		}
	}
}

void sudoku::displayBoard()
{
	for(row=1; row<10; row++)
	{
		for(col=1; col<10; col++)
		{
			cout<<board[row][col];
		}
		cout << "\n";
	}
}

void sudoku::genRandomInt(int randInt)
{
	int dummy = 0;
	int x = randInt;

	time_t seconds;	//variable to hold seconds on the clock
	time(&seconds);	//value from system clock is stored in seconds
	srand((unsigned int)seconds);	//convert seconds to unsigned int
	while(x > 0)
	{
		row = (rand() % 8) + 1;	//(HIGH - LOW + 1) + LOW = 9-1+1
		col = (rand() % 8) + 1;
		dummy = (rand() % 8) + 1;
		board[row][col] = dummy;
		cout << row <<col <<dummy <<'\n';
		//cout << board[row][col];
		x = x - 1;
	}
	displayBoard();
	//cout<< "\n generating preview of the basic layout of our board... \n";

}

void sudoku::getData(char choice)
{
	int col, row, number;
	char ch = choice;
	while (ch == 'y')
	{
		row_copy = row;
		col_copy = col;
		cout << "\n enter row-column-number: \n";
		cin >> row>> col >>number;
		board[row][col] = number;
		displayBoard();
		cout<<"\n Verifying status of board...\n";
		Verify();
		cout << "\n Would you like to continue? (y/n): ";
		cin >> ch;
	}
	cout << "\n Thank You for playing Sudoku!!";
	exit(0);
}

void sudoku::Verify()
{
	//true indicates no repetition
	bool status_row = true;	//row-wise check for repetition in entries
	int col1;
	for (row=1; row<10; row++)
	{
		for(col=1; col<10; col++)
		{
			if(board[row][col] == 0)
				continue;
			int flag_row = board[row][col];	//if no. isn't 0 then save it to check for repetition
			col1 = col;		//save index of the no. so as to check for repetition from the following index
			for(col = (col1+1); col<10; col++)
			{
				if((board[row][col]) == flag_row)
					status_row = false;
			}
		}
	}
	//column-wise check for repetition in entries
	bool status_col = true;
	int row1;
	for(col=1; col<10; col++)
	{
		for(row=1; row<10; row++)
		{
			if(board[col][row] == 0)
				continue;
			int flag_col = board[col][row];
			row1 = row;
			for(row = (row1+1); row<10; row++)
			{
				if((board[col][row]) == flag_col)
				{
					status_col = false;
					cout << "column verification";
				}
			}
		}
	}
	cout << "status " << status_row << status_col;
	if(status_row && status_col)
		cout <<"\n No repetition in numbers...";
	else
		cout << "\n Last entry is repeated \n";
}

int main()
{
	sudoku s;

	cout<< " Welcome to the game of Sudoku! (BETA STAGE) \n";
	cout<< "============================================\n";
	cout << "\n Generating the basic layout of our board...\n";

	s.genBoard();
	s.genRandomInt(5);	//auto-generating 5 random int on the board

	char ch = 'y';
	s.getData(ch);
	return 0;
}





