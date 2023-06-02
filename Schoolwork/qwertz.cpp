#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int calculateNumber(string fliesstext) {
    int zahl;
    if (zahl != stoi(fliesstext)) {
        return -1;
    }
    else {
        zahl = stoi(fliesstext);
    }
    return zahl;
}
string writeInFile(string fliesstext) {
    fstream f(output.txt);
    if (f.good) {
        fstream(ios::out);
        f.out << fliesstext;
        f.close;
    }

}
int writeInLog(string fliesstext) {
    int count;
    string Nachricht;
    fstream f(output.log);
    fstream(ios::out);
    if (f.good) {
        for (int index = 0; index < sizeof(fliesstext); index++) {
            int count = fliesstext[index];
        }
        cin >> count = cout << "printed " << count << "into file";
    }
    f.close;
}


int calculateAverageCharactersPerWord(int dateiName) {

}
int main() {


}