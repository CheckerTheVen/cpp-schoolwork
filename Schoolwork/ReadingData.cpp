#include <fstream>
#include <iostream>
#include <random>

void temporaryWritingData() {

	std::ofstream stream;
	stream.open("error.log");

	if (!stream.good()) {
		std::cout << "Error";
		return;
	}

	int ran;
	for (int i = 0; i < 1000; i++) {
		srand(i);
		fprintf(stream, "");
	}
}