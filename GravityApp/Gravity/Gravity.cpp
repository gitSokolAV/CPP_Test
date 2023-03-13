#include <iostream>
#include "constants.h"

double getInitialHeght()
{
	std::cout << "Enter the initial height of tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

double calculateeHeight(double initialHeght, int seconds)
{
	//[s = u * t + (a * t^2) / 2] 
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	double currentHeight = initialHeght - distanceFallen;

	return currentHeight;
}
void printHeight(double height, int seconds)
{
	if (height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at heght: " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}
void calculateAndPrintHeight(double initialHeight, int seconds)
{
	double height = calculateeHeight(initialHeight, seconds);
	printHeight(height, seconds);
}