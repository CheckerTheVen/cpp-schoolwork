#include <iostream>
#include <fstream>
#include <string>

#include "exercises.h"

void doAufgabe4() {

	using namespace four;

	std::cout << " E i n k a u f s k a l k u l a t i o n\n\n";
	char formatPreis[] = " |  %21s        %10.2fEUR  |\n", formatBezug[] = " |  %21s %5.2f%% %10.2fEUR  |\n";
	int selection = 0;
	double preis = 0, input = 0, rabatt = 0, skonto = 0, bezugskosten = 0;
	do {

		std::cout << "1 - Listeneinkaufspreis\n"
				  << "2 - Zieleinkaufspreis\n"
				  << "3 - Bareinkaufspreis\n"
				  << "4 - Bezugspreis\n"
				  << "0 - Beenden\n\n";

		std::cout << "gegeben: ";
		std::cin >> selection;
		std::cout << "\n\n";

		if (selection == 0) {
			break;
		}

		std::cout << "Preis: ";
		std::cin >> input;
		std::cout << "Rabatt: ";
		std::cin >> rabatt;
		std::cout << "Skonto: ";
		std::cin >> skonto;
		std::cout << "Bezugskosten: ";
		std::cin >> bezugskosten;
		std::cout << "\n\n";

		switch (selection) {
		case 1:
			preis = getListeneinkaufspreis(input);
			goto gohere;

		case 2:
			preis = getListeneinkaufspreis(input, rabatt);
			goto gohere;

		case 3:
			preis = getListeneinkaufspreis(input, rabatt, skonto);
			goto gohere;

		case 4:
			preis = getListeneinkaufspreis(input, rabatt, skonto, bezugskosten);
			goto gohere;

			gohere:

			printf(" +----------------------------------------------+\n");
			printf(formatPreis, "Listeneinkaufspreis", preis);
			printf(formatBezug, "- Rabatt", rabatt, -getRabatt(preis, rabatt)); 
			printf(" +----------------------------------------------+\n");
			printf(formatPreis, "Zieleinkaufspreis", getZieleinkaufspreis(preis, rabatt));
			printf(formatBezug, "- Skonto", skonto, -getSkonto(getZieleinkaufspreis(preis, rabatt), skonto));
			printf(" +----------------------------------------------+\n");
			printf(formatPreis, "Bareinkaufspreis", getBareinkaufspreis(preis, rabatt, skonto));
			printf(formatBezug, "+ Bezugskosten", rabatt, getBezugskosten(getBareinkaufspreis(preis, rabatt, skonto), bezugskosten));
			printf(" +----------------------------------------------+\n");
			printf(formatPreis, "Bezugspreis", getBezugspreis(preis, rabatt, skonto, bezugskosten));
			printf(" +----------------------------------------------+\n");
			std::cout << "\n";

		default:
			break;
		}

	} while (selection > 0);

}

int main() {

	doAufgabe4();
	return 0;
}