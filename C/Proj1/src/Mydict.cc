#include "Mydict.h"


oh::MyDict *oh::MyDict::_MyDict = createInstance(); //饱汉
pthread_once_t oh::MyDict::_po = PTHREAD_ONCE_INIT;
vector<pair<string, int>> oh::MyDict::_dict;
map<string, set<int>> oh::MyDict::_index_table;