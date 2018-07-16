#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

struct RssItem
{
    string title;
    string link;
    string description;
    string content;
};

class RssReader
{
  public:
    RssReader(string filename)
    {
        XMLDocument *doc = new XMLDocument(); //static_cast<const char *>(filename.c_str())
        if (doc->LoadFile(static_cast<const char *>(filename.c_str())) == XML_ERROR_FILE_NOT_FOUND)
        {
            cout << "read file error!" << endl;
            exit(-1);
        }
        XMLElement *root = doc->RootElement();
        parseRss(root, _rss);
        cout << _rss.size() << endl;
        for (auto i : _rss)
        {
            cout << i.link << endl;
        }
        cout << _rss[0].content << endl;
        delete doc;
    };
    void parseRss(XMLElement *root, vector<RssItem> &rss)
    {
        {
            RssItem RSS;
            XMLElement *channelNode = root->FirstChildElement("channel");
            XMLElement *itemNode = channelNode->FirstChildElement("item");
            if (itemNode == NULL)
            {
                cout << "No such node\n";
                return;
            }
            while (itemNode != NULL)
            {

                XMLElement *attribute = itemNode->FirstChildElement("title");
                if (attribute == NULL)
                {
                    cout << "No such attribute\n";
                    return;
                }

                cout << attribute->GetText();

                RSS.title = attribute->GetText();

                attribute = itemNode->FirstChildElement("link");
                if (attribute == NULL)
                {
                    cout << "No such attribute\n";
                    return;
                }

                RSS.link = attribute->GetText();
                attribute = itemNode->FirstChildElement("description");
                if (attribute == NULL)
                {
                    cout << "No such attribute description\n";
                    return;
                }
                RSS.description = attribute->GetText();
               
                attribute = itemNode->FirstChildElement("content:encoded");
                if (attribute == NULL)
                {
                    cout << "No such attribute\n";
                    return;
                }
                string content = attribute->GetText();
                regex pattern("<[^>]+>");
                content  =regex_replace(content, pattern, "");
                regex pattern2("&nbsp");
                RSS.content  =regex_replace(content, pattern2, "");
                //RSS.content = attribute->GetText();

                rss.push_back(RSS);
                itemNode = itemNode->NextSiblingElement(); //下一个兄弟节点
            }
        }
    }
    void dump(string filename = "pagelib.dat"){
        ofstream ofs(filename);
        int cnt = _rss.size();
        for (int i = 0; i < cnt; i++) {
            ofs<<"<doc>"<<'\n';
            ofs<<"<docid>"<<i+1<<"</docid>\n";
            ofs<<"<title>"<<_rss[i].title<<"</title>\n";
            ofs<<"<link>"<<_rss[i].link<<"</link>\n";
            ofs<<"<content>"<<_rss[i].content<<"</content>\n";
            ofs<<"</doc>"<<'\n';
        }
        ofs.close();

    };

  private:
    vector<RssItem> _rss;
};

int main()
{
    string filename;
    cout << "File name !" << endl;
    cin >> filename;

    RssReader RssReader(filename);
    RssReader.dump();

    //delete doc;
}