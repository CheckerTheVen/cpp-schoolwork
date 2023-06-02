#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace one {

	int calculateNumber(string text) {

		int errorVar = -1;

		// Returning an error when the number would exceed the integer's capacity.
		if (text.length() > 9) {
			return errorVar;
		}

		int num = 0;
		for (int cur = 0; cur < text.length(); cur++) {
			// Returning an error when the read character is not a number.
			if (!(text[cur] >= '0' && text[cur] <= '9')) {
				return errorVar;
			}
			// Multiplying 10 because all the integers we read so far would all
			// travel to the left by a digit.
			num *= 10;
			// Subtracting the value of the character '0' off the read character,
			// which would return the integer value of the character.
			num += text[cur] - '0';
		}
		return num;
	}

	void writeInLog(int words) {

		// Returning and writing no log when there were no words.
		if (words == 0) {
			return;
		}

		// Opening the stream.
		ofstream stream;
		stream.open("output.log", ios::app);

		// Returning if there was an error accessing into the file.
		if (!(stream.good())) {
			return;
		}

		// Printing a simple message how many words were written.
		stream << "Printed " << words << " lines into the file." << endl;

		// Closing the stream and returning.
		stream.close();
		return;
	}

	void writeInFile(string text) {

		// Returning when there is no text.
		if (text.length() == 0) {
			return;
		}

		// Opening the stream in append mode.
		ofstream stream;
		stream.open("output.txt", ios::app);

		// Returning if there was an error accessing into the file.
		if (!(stream.good())) {
			return;
		}

		string output = "";
		int words = 0;
		for (int cur = 0; cur < text.length(); cur++) {

			// Printing the existent output when the current character is a
			// punctuation character.
			if (text[cur] == ' ' || text[cur] == '\t' || text[cur] == '.'
				|| text[cur] == ',' || text[cur] == '?' || text[cur] == '!') {

				// Printing the output only when the existent output is not empty.
				if (output.length() > 0) {

					stream << output << endl;
					words++;
					output = "";
				}
			}
			// Appending the string when character is not a punctuation character.
			else {

				output += text[cur];
			}
		}

		// Closing the stream.
		stream.close();

		// Writing the logfile.
		return writeInLog(words);
	}

	float calculateAverageCharactersPerWord(string file) {

		// Opening the stream.
		ifstream stream;
		stream.open(file);

		// Returning if the stream is not good.
		if (!(stream.good())) {
			return -1;
		}

		string line;
		float countCharacters = 0, countWords = 0;
		bool isWordCurrently = false;
		// Reading as long as the end of the file hasn't been reached.
		while (!(stream.eof())) {

			getline(stream, line);
			for (int cur = 0; cur < line.length(); cur++) {

				if (line[cur] == ' ' || line[cur] == '.'
					|| line[cur] == ',' || line[cur] == '!'
					|| line[cur] == '?' || line[cur] == '\n') {

					// Increasing word count when the word ends.
					if (isWordCurrently) {
						countWords++;
						isWordCurrently = false;
					}
				}
				// Increasing the character count for every character that is not a
				// punctuation character.
				else {
					countCharacters++;
					isWordCurrently = true;
				}
			}
		}

		// Closing the stream and returning the character per word value.
		stream.close();
		return (countCharacters / countWords);
	}
}

namespace two {

	double getAbsoluteValue(double in) {
		if (in >= 0) {
			return in;
		}
		else {
			return in - (2 * in);
		}
	}

	int getRoundedValue(double in) {
		if (in >= 0) {
			return ((in - (int) in) < 0.5) ? (int) in : (int) in + 1;
		}
		else {
			return ((in - (int)in) > -0.5) ? (int)in : (int)in - 1;
		}
	}
	
	double getPower(double base, int exponent) {
		if (base == 1) {
			return 1;
		}

		if (base == 0) {
			return 0;
		}

		if (exponent == 0) {
			return 0;
		}

		double power;
		if (exponent > 0) {
			power = base;
			for (int i = 1; i < exponent; i++) {
				power *= base;
			}
		}
		else {
			power = 1 / base;
			for (int i = -1; i > exponent; i--) {
				power /= base;
			}
		}

		return power;
	}
}

namespace three {

	bool getNot(bool a) {
		return !a;
	}

	bool getAnd(bool a, bool b) {
		return a && b;
	}

	bool getOr(bool a, bool b) {
		return a || b;
	}

	bool getExclusiveOr(bool a, bool b) {
		return !(a == b);
	}

	void printBoolean(bool in) {
		std::cout << (in) ? "true" : "false";
		return;
	}
}

namespace four {

	double getRabatt(double listeneinkauspreis, double rabatt) {
		return listeneinkauspreis * (rabatt / 100);
	}

	double getSkonto(double zieleinkaufspreis, double skonto) {
		return zieleinkaufspreis * (skonto / 100);
	}

	double getBezugskosten(double bareinkaufspreis, double bezugskosten) {
		return bareinkaufspreis * (bezugskosten / 100);
	}


	double getZieleinkaufspreis(double listeneinkauspreis, double rabatt) { 
		return listeneinkauspreis - getRabatt(listeneinkauspreis, rabatt);
	}

	double getBareinkaufspreis(double zieleinkaufspreis, double skonto) {
		return zieleinkaufspreis - getSkonto(zieleinkaufspreis, skonto);
	}

	double getBezugspreis(double bareinkaufspreis, double bezugskosten) {
		return bareinkaufspreis + getBezugskosten(bareinkaufspreis, bezugskosten);
	}


	double getBareinkaufspreis(double listeneinkaufspreis, double rabatt, double skonto) {
		return getBareinkaufspreis(getZieleinkaufspreis(listeneinkaufspreis, rabatt), skonto);
	}

	double getBezugspreis(double zieleinkaufspreis, double skonto, double bezugskosten) {
		return getBezugspreis(getBareinkaufspreis(zieleinkaufspreis, skonto), bezugskosten);
	}

	double getBezugspreis(double listeneinkaufspreis, double rabatt, double skonto, double bezugskosten) {
		return getBezugspreis(getBareinkaufspreis(getZieleinkaufspreis(listeneinkaufspreis, rabatt), skonto), bezugskosten);
	}


	double getListeneinkaufspreis(double listeneinkaufspreis) {
		return listeneinkaufspreis;
	}

	double getListeneinkaufspreis(double zieleinkaufspreis, double rabatt) {
		return zieleinkaufspreis / (1 - (rabatt / 100));
	}

	double getListeneinkaufspreis(double bareinkaufspreis, double rabatt, double skonto) {
		return getListeneinkaufspreis(bareinkaufspreis / (1 - (skonto / 100)), rabatt);
	}

	double getListeneinkaufspreis(double bezugspreis, double rabatt, double skonto, double bezugskosten) {
		return getListeneinkaufspreis(bezugspreis / (1 + (bezugskosten / 100)), rabatt, skonto);
	}
}