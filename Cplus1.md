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

### 布尔数据

1、枚举类型：

格式：`enum 枚举名 {元素名1,元素名2,...,元素名n}`

例如：

```c++
enum Month{JAN,FEB,MAR,APR,MAY,JUN,JUL,AGU,SEP,OCT,NOV,DEC};
```

枚举类型声明中的元素为枚举文字，不是变量

**枚举类型变量的定义：**`Month month1;`

2、用户自定义类型

- `typedef`用于自定义数据类型别名

格式：`typedef 原类型标识 新类型名;`

例如：

```c++
typedef int INT;
//此时，INT为int别名
```

3、关系表达式

**关系操作符**和两个操作数构成的表达式，或多个关系表达式构成的复杂关系式。运算结果为逻辑值：`true or false`

C/C++早期使用`0`表示非真（false），`非零`表示真（true）。

**逻辑操作符：**

- 与`&&`
- 或`||`
- 非`!`

关系操作符与逻辑操作符的优先级（从高到低）：*非、小于、不小于、大于、不大于、等于、不等于、与、或。*

 **递增递减操作符：**

- 前缀递增递减：（`++a,--a`）先递增递减，再参与运算
- 后缀递增递减：（`a++,a--`）先参与运算，再递增递减

操作数必须是变量，不要在复杂的表达式中使用。