//Pimpl(pointer to implementation, 指向实现的指针)是一种常用的，
//用来对“类的接口与实现”进行解耦的方法。这个技巧可以避免在头文件中暴露私有细节(见下图1)，
//因此是促进API接口与实现保持完全分离的重要机制。
//但是Pimpl并不是严格意义上的设计模式(它是受制于C++特定限制的变通方案)，这种惯用法可以看作桥接设计模式的一种特例。
/*
降低耦合
信息隐藏
降低编译依赖，提高编译速度
接口与实现分离
*/
#ifndef __LINE_H__
#define __LINE_H__

class Line
{
  public:
    Line(int, int, int, int);
    ~Line();
    void printLine() const;

  private:
    class LineImpl;

  private:
    LineImpl *_pimpl;
};

#endif