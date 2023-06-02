#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace exam2 {

	using namespace std;

	string generatePassword(string text) {

		string pwd;
		for (int cur = 0; cur < text.length(); cur++) {
			// Appending the password only if the current character an
			// even number or an uppercase letter at the start of a word.
			if (text[cur] == '0' || text[cur] == '2' ||
				text[cur] == '4' || text[cur] == '6' ||
				text[cur] == '8' ||
				(text[cur] >= 'A' && text[cur] <= 'Z' &&
					((cur == 0) ? true : text[cur - 1] == ' '))) {

				pwd += text[cur];
			}
		}
		// Returning the password.
		return pwd;
	}

	void summarizeWorkingTime(string personnel) {

		// Returning and skipping the execution if the personnel parameter
		// is empty.
		if (personnel.length() == 0) {
			return;
		}

		// Opening the stream.
		ifstream stream;
		stream.open("Reinigung.txt");

		// Returning and skipping the execution if the stream is not good.
		if (!stream.good()) {
			return;
		}

		string line;
		int pivot, time = 0;
		while (!stream.eof()) {

			getline(stream, line);

			// Calculating the time when the personnel number is found in
			// this line.
			if (line.find(personnel) != string::npos) {
				pivot = line.find('\t');
				// Calculating the number and adding it to the time.
				time += ((line[pivot + 1]) - '0') * 10
					+ ((line[pivot + 2]) - '0');
			}
		}
		// Transforming the time into the hour/minute format.
		int hrs = time / 60;
		int mins = time % 60;
		// Printing the working time in the format above.
		cout << "Working time for personnel " << personnel << ": "
			<< hrs << ((hrs == 1) ? " hour" : " hours") << " and "
			<< mins << ((mins == 1) ? " minute" : " minutes") << ".\n";

		// Closing the stream and returning.
		stream.close();
		return;
	}

}