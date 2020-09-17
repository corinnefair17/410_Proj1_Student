/***
 * KP Utils
 */
#include <numeric>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "stdlib.h"

using namespace std;

//********************** private to this compilation unit **********************

vector<process_stats> stats;

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString) {
	return atoi(myString);
}

int loadData(const char *filename, bool ignoreFirstRow) {
	ifstream file(filename);
	string line;

	if (!file.good()) {
		return COULD_NOT_OPEN_FILE;
	}

	if (ignoreFirstRow) {
		getline(file, line);
	}

	while (getline(file, line)) {
		cout << line << endl;
	}

	return SUCCESS;
}

//will sort according to user preference
void sortData(SORT_ORDER mySortOrder) {

}

process_stats getNext() {
	process_stats myFirst;

	return myFirst;
}

//returns number of process_stats structs in the vector holding them
int getNumbRows() {
	return stats.size();
}

