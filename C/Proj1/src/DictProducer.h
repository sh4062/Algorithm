#ifndef _OH_DICTPRODUCER_H_
#define _OH_DICTPRODUCER_H_
#include <string>
#include <vector>
#include <map>
using namespace std;
namespace oh
{
class DictProducer
{
public:
  DictProducer(const string &dir);
  //    DictProducer(const string & dir, SplitTool*splitTool)
  void build_en_dict();
  //void build_cn_dict();
  void store_dict(const char *filepath);
  //    virtual ~SplitToolCppJieba();
  //virtual vector<string> cut(const string &sentence) = 0;
  void show_files() const;
  void show_dict() const;
  void get_files();
  void push_dict(const string &word);

private:
  string _dir;
  vector<string> _files;
  map<string, int> _dict;
  //    SplitTool*splitTool;
};
} // namespace oh
#endif