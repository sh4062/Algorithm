# Chapter 1. Getting Started
## 1.1 Introduction
### 1.1
### 1.2
## 1.2 I/O
### 1.3
```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```
### 1.4
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
    return 0;
}
```

### 1.5

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```

### 1.6
删除;.
## 1.3 注释
// /\*...\*/
### 1.7
### 1.8
## 1.4控制流Control Flow
### 1.9
```cpp
#include <iostream>

int main()
{
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val;
        ++val;
    }

    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}
```
while for if
## 1.4类Class
