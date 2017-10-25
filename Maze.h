//Maze.h : Declaretion of struct:'Item' and class:'Maze' for a simple maze game
#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <stack>
using std::pair;
using std::stack;

typedef pair<int, int> Point; //represent a point in maze

//struct:'Item' : Represent an item in a maze.
struct Item
{
	//x is row index of a 2D array while y is column index
	int x, y;
};


//class:'Maze' : Implement path function
class Maze
{
private:
	int **maze;
	int **mark;
	int nextDir;
	int row, column;

	Item item;

	Point start;
	Point finish;
	stack<Point> result;

	//priavate operations
	void _initMaze();
	bool _moveN();
	bool _moveS();
	bool _moveE();
	bool _moveW();

public:
	Maze(int row, int column, Point start, Point finish);
	bool Find();
	bool move(int nextDir);
	void printMaze();
	stack<Point> getPath();
};
#endif