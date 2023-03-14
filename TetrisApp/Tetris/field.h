#ifndef FIELD_H
#define FIELD_H
#include <SFML/Graphics.hpp>



// Playing field height
const int M = 20;

//Playing field width
const int N = 10;

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
} a[4], b[4];
#endif // !FIELD_H

