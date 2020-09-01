## C/C++基本语法

### 程序设计基本流程：

![image-20200901105530402](https://i.loli.net/2020/09/01/Rdb2NCq69jrKa8V.png)

### Linux编译C++文件

- gcc：编译c程序
- g++：编译c++程序

示例代码：

```c++
#include<iostream>

using namespace std;

int main()
{
        cout<<"Hello World";
}
```

在Linux下，使用g++编译文件的命令是：`g++ main.cpp`

![image-20200901112253118](https://i.loli.net/2020/09/01/6EvBsZzYPdQCf2c.png)

可以使用`-o`指定编译后的文件名：`g++ main.cpp -o hello`

![image-20200901112535950](https://i.loli.net/2020/09/01/5mSqBkJOXwQUxIT.png)

可以使用`./a.out`命令执行编译后的文件。



