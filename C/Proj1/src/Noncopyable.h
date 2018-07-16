#ifndef __OH_NONCOPYABLE_H__
#define __OH_NONCOPYABLE_H__

namespace oh
{

class Noncopyable
{
  protected:
	Noncopyable() {}
	~Noncopyable() {}

  private:
	Noncopyable(const Noncopyable &);
	Noncopyable &operator=(const Noncopyable &);
};

} // namespace oh

#endif