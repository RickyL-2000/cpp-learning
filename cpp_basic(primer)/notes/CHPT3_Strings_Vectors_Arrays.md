# 字符串、向量和数组

## 3.1 命名空间的using声明

有了using声明就无须专门的前缀(形容命名空间::)也能使用所需的名字了。用了using的语句，就可以直接访问命名空间中的名字:
example: 
    
    #include <iostream>
    using std::cin;
    int main()
    {
        int i;
        cin >> i;         //正确
        cout << i;        //错误
        std::cout << i;   //正确
        return 0;
    }

每个名字都需要独立的using声明，而头文件不应包含using声明

## 3.2 标准库类型string

使用string类型必须首先包含string头文件。作为标准库的一部分，string定义在命名空间std中。
example:

    #include <string>
    using std::string;

### 3.2.1 定义和初始化string对象

example:

    string s1;           //空字符串
    string s2 = s1;      //s2是s1的副本(拷贝初始化)
    string s2(s1);       //等价于上(直接初始化)
    string s3 = "hiya";  //s3是该字符串字面值的副本
    string s3("hiya");   //等价于上
    string s4(10,'c');   //cccccccccc

### 3.2.2 string对象上的操作

string的操作
|   operation    |                   意义                    |
| :------------: | :---------------------------------------: |
|    os << s     |       将s写到输出流os中，返回os(?)        |
|    is >> s     | 从is中读取字符串赋给s，以空白分隔，返回is |
| getline(is, s) |        从is中读取一行赋给s，返回is        |
|   s.empty()    |       s为空返回true，否则返回false        |
|    s.size()    |             返回s中字符的个数             |
|      s[n]      |       返回s中第n个字符的引用，从0起       |
|     s1+s2      |          返回s1和s2连接后的结果           |
|     s1=s2      |       用s2的副本代替s1中原来的字符        |
|     s1==s2     |                   相等                    |
|     s1!=s2     |                  不相等                   |
|  <, <=, >, >=  |                  不等号                   |

> example: exercise_getline.cpp
> 

#### string::size_type类型 (????)

size函数返回的是一个string::size_type类型的值

**NOTE**：如果一条表达式中已经有了size()函数就不要再使用int了，这样可以避免混用int和unsigned可能带来的问题。

### 3.2.3 处理string对象中的字符

cctype头文件：在C语言中，cctype头文件就是ctype.h头文件，只不过在C++中去掉了.h的后缀并在前面加上了c的前缀

cctype头文件中的函数
|  function   |                        meaning                        |
| :---------: | :---------------------------------------------------: |
| isalnum(c)  |                 当c是字母或数字时为真                 |
| isalpha(c)  |                    当c是字母时为真                    |
| iscntrl(c)  |                  当c是控制字符时为真                  |
| isdigit(c)  |                    当c是数字时为真                    |
| isxdigit(c) |                当c是十六进制数字时为真                |
| isgraph(c)  |               当c不是空格但可打印时为真               |
| islower(c)  |                  当c是小写字母时为真                  |
| isupper(c)  |                  当c是大写字母式为真                  |
| isprint(c)  |     当c是可打印字符时为真(c是空格或c具有可视形式)     |
| ispunct(c)  |                  当c是标点符号时为真                  |
| isspace(c)  | 空白时真(空格、横/纵向制表符、回车符、换行符、进纸符) |
| tolower(c)  |                  输出对应的小写字母                   |
| toupper(c)  |                  输出对应的大写字母                   |

#### 基于范围的for语句

可以用for语句遍历给定序列(比如string)中的每一个元素

example:

    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    //punct_cnt的类型和s.size的返回类型一样
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << endl;

#### 使用范围for语句改变字符串中的字符(!!!!!!)

要改变string对象中字符的值，必须把循环变量定义成引用类型。引用只是给定对象的一个别名，因此当使用引用作为循环控制变量时，这个变量实际上被依次绑定到了序列的每个元素上。

> example: 
> 
> range_for.cpp; 
> 
> exercise_string_empty_size.cpp
