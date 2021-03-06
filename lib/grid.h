#ifndef _GRID_
#define _GRID_

#include "common.h"

#define PLACE_HOLDER ' '

using namespace std;
/**
 *
 * Tic-Tac-Toe Grid class.
 *
 */
class grid
{
	private:
		char **p;
	public:
		void take_input(int, int, int);
		void display();
		int check(int, int);
		char game_over(void);
		grid(void);
};

/**
 * Constructor.
 * @params: None
 * 
 */
grid :: grid(void)
{
	p = new char *[3];

	for(int i = 0 ; i < 3 ; i++)
	{
		p[i]=new char[3];
		for(int j = 0 ; j < 3 ; j++)
		{
			p[i][j] = PLACE_HOLDER;
		}
	}
}

/**
 * To Take input from user.
 * @param: 
 *		r: row
 *		c: column
 * 		pl: player number
 * @retval:	None
 */
void grid :: take_input(int r, int c, int  pl)
{
	start:
	if((check(r,c)) == 1)
	{
		if(pl == 1) 
		{
			p[r-1][c-1] = 'X';	
		}
		else 
		{	
			p[r-1][c-1] = 'O';	
		}
	}
	else
	{
		cout << getTextColorString(RED) << "\nERROR:Wrong Entry!! Give the correct one:" << getTextColorString(WHITE);
		cin >> r >> c;
		goto start;
	}
}
/**
 * To display the game board on the screen.
 * @param: None
 * @retval: None
 */
void grid :: display(void)
{
	cout << getTextColorString(BLUE) << "\n    1    2    3  \n" << getTextColorString(WHITE);
	for(int i = 0 ; i < 3 ; i++)
	{
		cout << getTextColorString(BLUE) << i+1 << " " << getTextColorString(WHITE);
		for(int j = 0; j < 3 ; j++)
		{
			cout << getTextColorString(BLUE) << "| " << getTextColorString(WHITE);
			if( p[i][j] == 'X')
			{
				cout << getTextColorString(YELLOW) << p[i][j] << getTextColorString(WHITE);
			}
			else
			{
				cout << getTextColorString(GREEN) << p[i][j] << getTextColorString(WHITE);
			}
			cout << getTextColorString(BLUE) << " |" << getTextColorString(WHITE);
		}
		cout << "\n";
	}
}

/**
 * Checks whether the field (r,c) is empty or not.
 *	@param: row, column
 *	@retval: integer. 1: if empty, 0: otherwise
 */
int grid :: check(int row, int col)
{
	if( (row>0 && col>0 && row<4 && col<4) && p[row-1][col-1] == PLACE_HOLDER)
	{	
		return 1;	
	}
	
	return 0;
}

/**
 * To check for game over.
 * @params: None
 * @retval: character
 		'X' : if player 'X' is winner 
 		'O' : if player 'O' is winner 
 		'C' : if there're some empty fields in game board
 		'Z' : otherwise
 */

char grid :: game_over(void)
{
	if(p[0][0] == p[0][1] && p[0][0] == p[0][2])  {	return p[0][0];	}
	if(p[0][0] == p[1][0] && p[0][0] == p[2][0])  {	return p[0][0];	}
	if(p[0][0] == p[1][1] && p[0][0] == p[2][2])  {	return p[0][0];	}
	if(p[2][2] == p[2][1] && p[2][2] == p[2][0])  {	return p[2][2];	}
	if(p[2][2] == p[1][2] && p[2][2] == p[0][2])  {	return p[2][2];	}
	if(p[2][0] == p[1][1] && p[1][1] == p[0][2])  {	return p[1][1];	}
	if(p[0][1] == p[1][1] && p[1][1] == p[2][1])  {	return p[1][1];	}
	if(p[1][1] == p[1][0] && p[1][1] == p[1][2])  {	return p[1][1];	}

	int cnt = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3 ; j++)
		{
			if(p[i][j] == PLACE_HOLDER)
			{
				cnt++;
			}
		}
	}
	if(cnt != 0)
	{
		return 'C';
	}
	
	return 'Z';
}


#endif