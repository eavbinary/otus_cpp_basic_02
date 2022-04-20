#include <iostream>
#include <ctime>
#include <fstream>
#include <map>

using std::cout;
using std::cin;
using std::string;

int getRandomNumber(int maxValue) {
    std::srand(std::time(nullptr));
    return std::rand() % maxValue;
}

int startGame(int hiddenNumber) {
    int gamerNumber;
    int attempt = 1;
    while (true) {
        cout << "Enter your guess:";
        cin >> gamerNumber;
        if (gamerNumber > hiddenNumber) {
            cout << "Less than " << gamerNumber << std::endl;
        } else if (gamerNumber < hiddenNumber) {
            cout << "Greater than " << gamerNumber << std::endl;
        } else {
            cout << "You win! Attempts = " << attempt << std::endl;
            break;
        }
        attempt++;
    }
    return attempt;
}

std::map<string, int> readScoreTable(string &fileName) {
    string username;
    string line;
    int score;

    std::ifstream scoreFile;
    scoreFile.open(fileName);

    std::map<string, int> arrScore;

    while (getline(scoreFile, line)) {
        size_t pos = line.find("\t");
        score = std::stoi(line.substr(pos));
        username = line.substr(0, pos);

        if (arrScore[username] == 0 || score < arrScore[username]) {
            arrScore[username] = score;
        }
    }
    scoreFile.close();
    return arrScore;
}

void showScoreTable(std::map<string, int> &arrScore) {
    std::map<string, int>::iterator arr = arrScore.begin();
    for (int i = 0; arr != arrScore.end(); arr++, i++) {
        cout << arr->first << "\t" << arr->second << std::endl;
    }
}

void writeSoreTable(string &fileName, std::map<string, int> &arrScore) {
    std::ofstream scoreFile;
    scoreFile.open(fileName);
    std::map<string, int>::iterator arr = arrScore.begin();
    for (int i = 0; arr != arrScore.end(); arr++, i++) {
        scoreFile << arr->first << "\t" << arr->second << std::endl;
    }
    scoreFile.close();
}