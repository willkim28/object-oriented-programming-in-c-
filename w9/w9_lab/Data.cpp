// Workshop 9
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Data.cpp

#include "Data.h"
using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
			int popGrowth = population[n - 1] - population[0];
			cout << "Population change from " << year[0] << " to " << year[n-1] << " is ";
			cout << fixed << setprecision(2);
			cout << static_cast<double>(popGrowth)/1000000 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
			bool vC = (violentCrimeRate[n-1] > violentCrimeRate[0]);
			const char *upDown = (vC) ? "up" : "down";
			cout << "Violent Crime trend is " << upDown << endl;

		// Q3 print the GTA number accurate to 0 decimal places
			cout << "There are " << fixed << setprecision(2) << average(grandTheftAuto, n) / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
			cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
			cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;

	}
}