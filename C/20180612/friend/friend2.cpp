#include <cmath>
#include <iostream>
using namespace std;
class Point;
class Line 
{
    public:
        float distance(const Point & lhs, const Point & rhs);

};
class Point 
{
    public:
        Point(int ix = 0, int iy = 0)
        : _ix(ix)
        , _iy(iy)
        {
            cout<<"Point:"<<endl;
        }

        void print() const {
            cout<<"("<<_ix<<","<<_iy<<")"<<endl;
        }
        
        friend float Line:: distance(const Point &a, const Point &b);//引用!!!
    private:
        int _ix;
        int _iy;

};

float  Line::distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
				(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}
int main(void)
{
	Point pt1(1, 2);
	Point pt2(3, 4);
    Line l;
	cout << "pt1和pt2之间的距离: " << l.distance(pt1, pt2) << endl;

	return 0;
}