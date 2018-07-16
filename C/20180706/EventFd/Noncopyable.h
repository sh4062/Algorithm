#ifndef __M_NONCOPYABLE_H__
#define __M_NONCOPYABLE_H__


namespace m
{

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable&);
	Noncopyable & operator=(const Noncopyable &);
};

}//end of namespace m

#endif