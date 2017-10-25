//Maze.cpp : Implementations of class:Maze'
#include "Maze.h"
#include <ctime>
#include <random>
#include <cstdlib>
using namespace std;

//Constrcutor
Maze::Maze(int row, int column, Point start, Point finish)
	:row(row)
	, column(column)
	, start(start)
	, finish(finish)
	, nextDir(1)
	, result(stack<Point>())
{
	_initMaze();

	item.x = start.first;
	item.y = start.second;
}


//Private Operations
/*
	Create the maze randomly.

	Return:void
*/
void Maze::_initMaze()
{
	//randomly create the maze
	maze = new int*[row];
	mark = new int*[row];
	for (int i = 0; i < row; i++)
	{
		maze[i] = new int[column];
		mark[i] = new int[column];
	}

	srand(time(0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			maze[i][j] = rand() % 2;
			mark[i][j] = 0;
		}
	}

	//some initial operations
	maze[start.first][start.second] = 1;
	maze[finish.first][finish.second] = 1;
	mark[start.first][start.second] = 1;
	result.push(start);
}


//Move functions
bool Maze::_moveN()
{
	if ((item.y - 1) < 0 || maze[item.y - 1][item.x] == 0 || mark[item.y - 1][item.x] == 1)
	{
		return false;
	}
	else
	{
		item.y--;
		mark[item.y][item.x] = 1;
		return true;
	}
}

bool Maze::_moveE()
{
	if ((item.x + 1) == column || maze[item.y][item.x + 1] == 0 || mark[item.y][item.x + 1] == 1)
	{
		return false;
	}
	else
	{
		item.x++;
		mark[item.y][item.x] = 1;
		return true;
	}
}

bool Maze::_moveS()
{
	if ((item.y + 1) == row || maze[item.y + 1][item.x] == 0 || mark[item.y + 1][item.x] == 1)
	{
		return false;
	}
	else
	{
		item.y++;
		mark[item.y][item.x] = 1;
		return true;
	}
}

bool Maze::_moveW()
{
	if ((item.x - 1) < 0 || maze[item.y][item.x - 1] == 0 || mark[item.y][item.x - 1] == 1)
	{
		return false;
	}
	else
	{
		item.x--;
		mark[item.y][item.x] = 1;
		return true;
	}
}


//Public operations
/*
	Print the maze.

	Return:void
*/
void Maze::printMaze()
{
	cout << "Random Maze:\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << maze[i][j] << "  ";
		}
		cout << endl;
	}
}


/*
	Get move path of item.

	Return:stack<Point>		Moving path.
*/
stack<Point> Maze::getPath()
{
	return result;
}



/*
Find a path from start to finish.

Return:stack<point>		Path to finish.
*/
bool Maze::Find()
{
	int size = result.size();

	//Reach at finish position
	if (item.x == finish.first && item.y == finish.second)
	{
		return true;
	}

	//Way to go
	bool flag = move(nextDir);
	//This move is valid
	if (flag)
	{
		result.push(Point(item.x, item.y));
		nextDir = 1;
		//Reach at finish position
		if (item.x == finish.first && item.y == finish.second)
		{
			return true;
		}
		else
		{
			Find();
		}
	}
	else
	{
		//If all the directions are unavailable
		if (nextDir >= 4 && result.size() == size)
		{
			result.pop();
			//If all the paths are invalid
			if (result.empty())
			{
				return false;
			}
			//Some way to move
			else
			{
				//reset
				item.x = result.top().first;
				item.y = result.top().second;
				nextDir = 1;
				Find();
			}
		}
		else
		{
			++nextDir;
			Find();
		}
	}
}


/*
	Move item by given number of direction.

	Parameter:nextDir	int		Number of direction.
								(1 for N,1 for E, 3 for S, 4 for W)

	Return:bool		Whether this move is valid.
*/
bool Maze::move(int nextDir)
{
	bool result = false;
	switch (nextDir)
	{
	case 1:
		result = _moveN();
		break;
	case 2:
		result = _moveE();
		break;
	case 3:
		result = _moveS();
		break;
	case 4:
		result = _moveW();
		break;
	default:
		break;
	}
	return result;
}
