#include <bits/stdc++.h>
using namespace std;
class txt
{
  public:
    txt()
    {
        _lines.reserve(11111);
    };
    ~txt(){};
    void readFile(const string filename);
	void query(const string & word);
    void processWord(const string &word, int line_no);

  private:
    void word();

  private:
    vector<string> _lines;
    map<string, set<int>> _word2line;
    map<string, int> _dict;
};
void txt::processWord(const string &word, int line_no)
{
    for (auto &ch : word)
    {
        if (!isalpha(ch))
            return;
    }
    ++_dict[word];
    _word2line[word].insert(line_no);
}

void txt::readFile(const string filename)
{
    ifstream ifs(filename);
    if (!ifs)
    {
        cout << "ifstream open error!" << endl;
        return;
    }
    string line;
    _lines.push_back(line);
    int line_no = 1;
    while (getline(ifs, line))
    {
        _lines.push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            processWord(word, line_no);
        }
        ++line_no;
    }
    ifs.close();
}



void txt::query(const string &word)
{
    cout << word << " occurs " << _dict[word] << ((_dict[word] > 1) ? " times." : " time.") << endl;
    for (auto &line_no : _word2line[word])
    {
        cout << "(line " << line_no << ") " << _lines[line_no] << endl;
    }
}

int main(int argc,char ** argv)
{
	if(argc != 2)
	{
		cout << "filename" << endl;
		return 0;
	}
	txt ts;
	ts.readFile(argv[1]);
	string word;
	while(cin >> word)
	{
		ts.query(word);
	}
	return 0;
}