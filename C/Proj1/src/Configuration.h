#ifndef _OH_CONFIGURATION_H_
#define _OH_CONFIGURATION_H_
#include <string>
#include <map>
using namespace std;
namespace oh
{
class Configuration
{
public:
  Configuration(const string &filepath);
  map<string, string> &getConfigMap();
  map<string, string> _configMap;
private:
  string _filepath;
  
};
} // namespace oh
#endif