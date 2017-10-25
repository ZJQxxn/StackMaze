//main.cpp : Test Find function of class:'Maze'
#include "Maze.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
	Maze maze(5, 5, Point(0, 0), Point(4, 4));
	maze.printMaze();

	cout << "Find a path ?  " << boolalpha << maze.Find() << endl;
	stack<Point> result = maze.getPath();

	cout << "Path length:" << result.size() << endl;
	cout << "Path from finish to start:\n ";
	while (!result.empty())
	{
		cout << '(' << result.top().second << ',' << result.top().first << ')' << "--->";
		result.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}