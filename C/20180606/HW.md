# HW
1. C++内存布局分布
 1. 栈区(Stack)系统分配释放，函数参数，局部变量
 2. 堆区（Heap）程序员分配释放
 3. 全局/静态（Static）全局变量+静态
 4. 文字常量:字符串常量
 5. 程序代码区：函数体的二进制代码
2. 编译器会为类自动生成
 1. 构造函数
 2. 析构函数
 3. 拷贝构造函数
    1.深浅拷贝只有单个形参，而且该形参是对本类类型对象的引用（常用const修饰），这样的构造函数称为拷贝构造函数。拷贝构造函数是特殊的构造函数，创建对象时使用已存在的同类对象来进行初始化，由编译器自动调用。
    2.(1)、它是构造函数的重载。
      (2)、它的参数必须使用同类型对象的引用传递
      (3)、如果没有显示定义，系统会自动合成一个默认的拷贝构造函数。默认的拷贝构造函数会依次拷贝类的数据成员完成初始化。
    3、使用场景
      (1) 对象实例化对象
       Date d1(1900,1,1);
       Date d2(d1);
      (2) 传值方式作为函数的参数
       Void FunTest(const Date date)
       {}
      (3) 传值方式作为函数的返回值
       Date FunTest()
       {
         Date date;
         return date;
       }
3. 深浅拷贝
浅拷贝只拷贝指针，但拷贝后两个指针指向同一个内存空间；深拷贝不但对指针进行拷贝，而且对指针指向的内容进行拷贝，经深拷贝后的指针指向两个不同地址。当类成员不包括指针何引用时，浅拷贝并无问题；但对于指针与引用成员，当对象的生命周期结束后，浅拷贝会造成同一块内存单元被释放两次，导致内存泄漏。

4. String
class String
{
public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();

	void print();

private:
	char * _pstr;
};

int main(void)
{
	String str1;
	str1.print();
	
	String str2 = "Hello,world";
	String str3("wangdao");
	
	str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();
	
	return 0;
}