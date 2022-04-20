#include <iostream>
#include "game.h"

using std::cout;
using std::cin;
using std::string;

int main(int argc, char **argv) {
    string high_scores_filename = "high_scores.txt";

    int maxNumber = 100;
    std::map<string, int> arrScore = readScoreTable(high_scores_filename);

    if (argc > 3) {
        cout << "Error! Use one parametr." << std::endl;
        cout << "[-max xxx] [-table] [-level [1..3]]" << std::endl;
    } else if (argc > 1) {
        if (string(argv[1]) == "-max") {
            if (argc == 3) {
                maxNumber = std::stoi(argv[2]);
            }
        } else if (string(argv[1]) == "-level") {
            if (argc == 3) {
                int level = std::stoi(argv[2]);
                switch (level) {
                    case 1:
                        maxNumber = 10;
                        break;
                    case 2:
                        maxNumber = 50;
                        break;
                    case 3:
                        maxNumber = 100;
                        break;
                    default:
                        cout << "Level value from 1 to 3" << std::endl;
                        return 0;
                }
            }
        } else if (string(argv[1]) == "-table") {
            showScoreTable(arrScore);
            return 0;
        }
    }

    string gamerName;
    cout << "Hi! Enter your name, please:";
    cin >> gamerName;

    int hiddenNumber = getRandomNumber(maxNumber);

    int attempt = startGame(hiddenNumber);

    if (arrScore[gamerName] == 0 || attempt < arrScore[gamerName]) {
        arrScore[gamerName] = attempt;
    }

    showScoreTable(arrScore);
    writeSoreTable(high_scores_filename, arrScore);

    return 0;
}
