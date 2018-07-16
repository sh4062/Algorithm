#include <cmath>
#include <iostream>
using namespace std;
class Point;
class Line
{
  public:
    float distance(const Point &lhs, const Point &rhs);
    void setPoint(int ix, int iy, Point & pt);
  private:
    int _iz;
};
class Point
{
  public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix), _iy(iy)
    {
        cout << "Point:" << endl;
    }

    void print() const
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

    //友元之友元类
    //friend class Line;
    friend Line; // 一定是破坏了类的封装性
        //友元是单向的, 不具备传递性, 不能继承
        //
        //A -> B, B -> C  ==> A -> C
    // void setZ(Line & line, int iz)
	// {//Point不能访问Line的私有成员
	// 	line._iz = iz;
	// }
  private:
    int _ix;
    int _iy;
};

float Line::distance(const Point &lhs, const Point &rhs)
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