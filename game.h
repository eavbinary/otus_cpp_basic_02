#include <map>

int getRandomNumber(int maxValue);
int startGame(int hiddenNumber);
std::map<std::string, int> readScoreTable(std::string &fileName);
void writeSoreTable(std::string &fileName, std::map<std::string, int> &arrScore);
void showScoreTable(std::map<std::string,int> &arrScore);
