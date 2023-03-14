#ifndef FIELD_H
#define FIELD_H
#include <SFML/Graphics.hpp>

using namespace sf;

// Playing field height
const int M = 20;

//Playing field width
const int N = 10;

int field[M][N] = { 0 };

int figures[7][4] =
{
	1,3,5,7, //I
	2,4,5,7, //S
	3,5,4,6, //Z
	3,5,4,7, //T
	2,3,5,7, //L
	3,5,7,6, //J
	2,3,4,5, //0
};
struct Point
{
	int x, y;
}a[4], b[4];

bool check()
{
	for (int i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;

	return 1;
}


#endif // !FIELD_H

