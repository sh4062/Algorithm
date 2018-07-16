#include "nestclass.h"
#include <cmath>
#include <iostream>
using namespace std;

class Line::LineImpl
{
    class Point
    {
      public:
        Point(int ix = 0, int iy = 0)
            : _ix(ix), _iy(iy)
        {
            cout << "Point(int=0, int=0)" << endl;
        }

        void print() const
        {
            cout << "(" << _ix
                 << "," << _iy
                 << ")";
        }

      private:
        int _ix;
        int _iy;
    };

  public:
    LineImpl(int x1, int y1, int x2, int y2)
        : _p1(x1, y1), _p2(x2, y2)
    {
        cout << "Point(int=0, int=0)" << endl;
    }
    ~LineImpl();

    void printLine() const;

  private:
    Point _p1;
    Point _p2;
};

void Line::LineImpl::printLine() const
{
    _p1.print();
    cout << " --> ";
    _p2.print();
    cout << endl;
}

Line::Line(int x1, int y1, int x2, int y2)
    : _pimpl(new LineImpl(x1, y1, x2, y2))
{
    cout << "Line(int,int,int,int)" << endl;
}

Line::~Line()
{
    delete _pimpl;
    cout << "~Line()" << endl;
}

void Line::printLine() const
{
    _pimpl->printLine();
}