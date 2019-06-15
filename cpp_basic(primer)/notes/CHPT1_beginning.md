# CHPT 1 Beginning

## 1.2 初识输入与输出

库iostream分别表示输入流(istream)和输出流(ostream)

### 标准库输入输出对象

> 标准库：std
> 作用域运算符： ::
前缀std指出cout和endl是定义在名为std的命名空间(namespace)中的

标准库定义了四个IO对象：
1. cin 标准输入
2. cout 标准输出
3. cerr 输出警告和错误消息 标准错误(standard error)
4. clog 输出一般性信息

> example *library.cpp*

### 头文件

> iostream
通常情况下，#include指令必须出现在所有函数之外（开始位置）

### 向流写入数据

> 输出运算符 <<
输出运算符接受**两个**运算对象：左侧是ostream对象，右侧是要打印的值

程序也可以改为：
std::cout << "Enter two numbers:";
std::cout << std::endl;

> 操纵符(manipulator)：endl
这个操作符的效果是结束当前行，**并将与设备关联的缓冲区(buffer)中的内容刷到设备中**。

> 缓冲区 buffer： 一个存储区域，用于保存数据。IO设施通常将输入输出数据保存在一个缓冲区中，读写缓冲区的动作与程序中的动作是无关的。
默认情况下，读cin会刷新cout；程序非正常终止时也会刷新cout。

> 输入运算符 >>

**NOTE** 输入运算不用加"std::endl"

## 1.4 控制流

### 1.4.1 while 语句

> example: while_statement.cpp

> 前缀递增运算符 ++

> 前缀递减运算符 --

**NOTE** 一次循环后cout默认换行

### 1.4.2 for 语句

> example: for_statement.cpp

每个for语句包含两部分：循环头和循环体。
循环头控制循环体的执行次数，由三部分组成：
1. 初始化语句 (init-statement)
> int val = 1
2. 循环条件 (condition)
> val <= 10
3. 表达式 (expression)
> ++val

**NOTE**: 如果循环变量在for循环头中定义，那么该变量是局域变量，不能在循环外使用。

### 1.4.3 读取数量不定的输入数据

> example: exercise1-16.cpp

核心思想：不断循环，直到没有新的输入为止

**NOTE** 用istream对象作为条件时，其效果时检测流的状态。
         如果流时有效的，那么检测成功，返回true
         如果遇到文件结束符(end-of-file)，或遇到一个无效输入时（例如输入的不是整数），istream的对象的状态就会变为无效。返回false。

**NOTE** 在windows系统中指出文件结束，是输入Ctrl+Z+Enter.
         在UNIX和Mac OS X系统中，输入Ctrl+D

### 1.4.4 if 语句

> example: if_statement.cpp
NOTE: 这个程序有个致命的缺点，就是如果重复的数据是错开的(如：1, 2, 2, 3, 2), 那么程序就会把前后的两组2分开计算，比如(2 times 2, 1 times 1, 1 times 2)

改进过的程序：
> example: if_stm_improved.cpp (未完成)

这种稍微复杂的嵌套需要花一些时间理解了。

## 1.5 类简介

> example: class_intro.cpp (然而并不存在Sales_item.h的头文件)

在C++中，我们通过定义一个类(class)来定义自己的数据结构。
每个类实际上都定义了一个新的类型。
example: Sales_item item

**NOTE**: 对于不属于标准库的头文件，用双引号包围("Sales_item.h")

对象的加法

(?)**NOTE**： 使用文件重定向

### 1.5.2 intro to 成员函数 (member function)

example: item1.isbn()
这就是在调用名为isbn的成员函数。成员函数是定义为类的一部分的函数，有时候也被成为方法(method)。