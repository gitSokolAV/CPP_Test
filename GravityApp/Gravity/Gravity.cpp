#include <iostream>
#include "Gravity.h"

int main()
{
	const double initialHeight = getInitialHeght();
	calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);
	calculateAndPrintHeight(initialHeight, 6);
	calculateAndPrintHeight(initialHeight, 7);
	calculateAndPrintHeight(initialHeight, 8);
	calculateAndPrintHeight(initialHeight, 9);
	calculateAndPrintHeight(initialHeight, 10);

	return 0;
}