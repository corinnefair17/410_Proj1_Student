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
	// Make sure stats is an empty vector
	stats = { };

	// Open file and create a string to hold each line
	ifstream file(filename);
	string line;

	// Make sure the file is good, otherwise return error code
	if (!file.good()) {
		return COULD_NOT_OPEN_FILE;
	}

	// If we ignore the first row, read it without doing anything to go to next row
	if (ignoreFirstRow) {
		getline(file, line);
	}

	while (getline(file, line)) {
		// Initialize temporary vector to hold values
		vector<int> values;

		// Create stringstream to read line by delimiter & add values to temp vector
		stringstream ss(line);
		string value;
		while (getline(ss, value, CHAR_TO_SEARCH_FOR)) {
			values.push_back(stringToInt(value.c_str()));
		}

		// ONLY process line if there are the right number of arguments
		if (values.size() == 4) {
			process_stats s;
			s.io_time = values.back();
			values.pop_back();
			s.cpu_time = values.back();
			values.pop_back();
			s.start_time = values.back();
			values.pop_back();
			s.process_number = values.back();
			values.pop_back();
			stats.push_back(s);
		}
	}

	file.close();

	return SUCCESS;
}


// Helper method to sort by CPU Time
bool compareCpuTime(process_stats &a, process_stats &b) {
	return a.cpu_time < b.cpu_time;
}

// Helper method to sort by Process Number
bool compareProcessNumber(process_stats &a, process_stats &b) {
	return a.process_number < b.process_number;
}

// Helper method to sort by start time
bool compareStartTime(process_stats &a, process_stats &b) {
	return a.start_time < b.start_time;
}

// Helper method to sort by IO Time
bool compareIOTime(process_stats &a, process_stats &b) {
	return a.io_time < b.io_time;
}

//will sort according to user preference
void sortData(SORT_ORDER mySortOrder) {
	switch(mySortOrder) {
	case CPU_TIME:
		sort(stats.begin(), stats.end(), compareCpuTime);
		break;
	case PROCESS_NUMBER:
		sort(stats.begin(), stats.end(), compareProcessNumber);
		break;
	case START_TIME:
		sort(stats.begin(), stats.end(), compareStartTime);
		break;
	case IO_TIME:
		sort(stats.begin(), stats.end(), compareIOTime);
		break;
	}
}

process_stats getNext() {
	process_stats myFirst;

	return myFirst;
}

//returns number of process_stats structs in the vector holding them
int getNumbRows() {
	return stats.size();
}

