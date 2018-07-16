#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Dictionary
{
  public:
    //......
    void read(const std::string &filename)
    {
        ifstream file(filename);
        string s;
        while (file >> s)
        {
            
            if ((!isalpha(s[0]))||(!isalpha(s[s.size()-1])))
            {
                continue;
            }
            std::map<string, int>::iterator it;
            it = _dict.find(s);
            if (it == _dict.end())
            {
                _dict.insert(pair<string, int>(s, 1));
            }
            else
            {
                it->second++;
            }
        }
        file.close();
    }
    void store(const std::string &filename)
    {
        ofstream file(filename);
        for (auto i:_dict) {
            file<<i.first<<endl;
             // <<" "<<i.second<<endl;
            cout<<i.first<<" "<<i.second<<endl;
        }
        file.close();
    }

  private:
    //......
    map<string, int> _dict;
};

int main()
{
    Dictionary d;
    d.read("b.txt");
    
    d.store("en_dict.txt");
}
