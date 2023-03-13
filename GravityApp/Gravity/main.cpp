#include <iostream>
#include "Gravity.h"

int main()
{
	const double initialHeight = getInitialHeght();
	for (int i = 0; i < 11; i++)
	{
		calculateAndPrintHeight(initialHeight, i);
	}
	return 0;
}