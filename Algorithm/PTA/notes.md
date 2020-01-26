# NOTES for study of PTA

## containers

### pair

> header: <utility>

|                         |                                  |
| :---------------------: | :------------------------------: |
|     pair<T1, T2> p1     | 创建一个空pair对象，采用值初始化 |
| pair<T1, T2> p1(v1, v2) | 创建一个pair对象，用v1, v2初始化 |
|    make_pair(v1, v2)    |       返回v1, v2创建的对象       |
|         p1 < p2         |             字典顺序             |
|        p1 == p2         |               相等               |
|         p.first         |        第一个公有数据成员        |
|        p.second         |          第二个公有成员          |

## string type

### 定义和初始化string对象

example:

    string s1;           //空字符串(不需要初始化字符数组的大小，这一点和C不一样)
    string s2 = s1;      //s2是s1的副本(拷贝初始化)
    string s2(s1);       //等价于上(直接初始化)
    string s3 = "hiya";  //s3是该字符串字面值的副本
    string s3("hiya");   //等价于上
    string s4(10,'c');   //cccccccccc

### string对象上的操作

string的操作
|    operation     |                   意义                    |
| :--------------: | :---------------------------------------: |
|     os << s      |       将s写到输出流os中，返回os(?)        |
|     is >> s      | 从is中读取字符串赋给s，以空白分隔，返回is |
|  getline(is, s)  |     从is中读取一行赋给s，返回is的状态     |
|    s.empty()     |       s为空返回true，否则返回false        |
|     s.size()     |             返回s中字符的个数             |
|       s[n]       |       返回s中第n个字符的引用，从0起       |
|      s1+s2       |          返回s1和s2连接后的结果           |
|      s1=s2       |       用s2的副本代替s1中原来的字符        |
|      s1==s2      |                   相等                    |
|      s1!=s2      |                  不相等                   |
|   <, <=, >, >=   |           不等号(**字典顺序**)            |
| s.substr(pos, n) |      返回从pos位置开始n个字符的子串       |
|    s.c_str()     |        返回C格式的字符数组的字符串        |
(以上的is,os分别是istream和ostream的缩写)

**NOTE**:
1. 在用scanf()等函数读取字符串的内容时，需要用.c_str()函数



#### string::size_type类型

size()函数返回的是一个string::size_type类型的值

在C++11新标准中，允许编译器通过auto或者decltype来推断变量的类型。example:

    auto len = line.size();  //len的类型是string::size_type

**NOTE**：如果一条表达式中已经有了size()函数就不要再使用int了，这样可以避免混用int和unsigned可能带来的问题。例如，假设n是一个具有负值的int，则表达式s.size() < n的判断结果几乎肯定是true，因为负值n会自动地转换成一个比较大的无符号值。所以在用index遍历string(或者vector)的时候，尽量用size_t i定义



### 处理string对象中的字符

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

可以用for语句遍历给定序列(比如string)中的每一个元素 (貌似C里面不能这么写)

example:

    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    //punct_cnt的类型和s.size的返回类型一样
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << endl;

#### **使用范围for语句改变字符串中的字符**  (!!!!!!)

要改变string对象中字符的值，必须把循环变量定义成引用类型。引用只是给定对象的一个别名，因此当使用引用作为循环控制变量时，这个变量实际上被依次绑定到了序列的每个元素上。

> example: 
> 
> range_for.cpp; 
> 
> exercise_string_empty_size.cpp

    string s("Hello World!!!");
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;

#### 下标运算符

下标运算符[]接收的输入参数是string::size_type类型的值，这个参数表示要访问的字符的位置，返回值是该位置上字符的**引用**。(从0计起)

**NOTE**： string对象的下标必须大于等于0而小于s.size()，使用超出此范围的下标将引发不可预知的结果，使用下标访问空string也会。所以，**在访问指定字符之前，首先检查s是否为空**

使用下标执行迭代，example:

    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]);index++)
        s[index] = toupeer(s[index]);
    //依次处理s中的字符直至处理完全部字符或者遇到一个空白

当输入: some string的时候，程序将输出：

    SOME string

#### 迭代器

严格来说，string对象不属于容器类型，但是string支持很多与容器类型类似的操作。比如迭代器和下标操作。



### string与其他类型的转化

#### sstream

#### atoi()




## header <algorithm>

### fill()

prototype:  ```fill(begin, end, val)```

### sort()



