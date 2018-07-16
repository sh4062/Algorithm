#ifndef _OH_CACHE_MANAGE_H_
#define _OH_CACHE_MANAGE_H_
#include "Cache.h"
#include <vector>
using namespace std;
namespace oh
{
class CacheManage
{
public:
  static void initCache(size_t idx, const string &filename)
  {

    return;
  };
  static Cache &getCache(size_t idx)
  {
    return _cacheList[idx];
  };
  static void periodicUpdateCaches()
  {
    for (auto &it : _cacheList)
    {
      //it.update();
    }
  };

private:
  static vector<Cache> _cacheList;
};
} // namespace oh
#endif