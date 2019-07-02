# 操作符和语句

## 循环结构

### while 语句

> example: while_statement.cpp

前缀递增运算符 ++
前缀递减运算符 --

**NOTE**: 
1. endl默认换行


### for 语句

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

**NOTE**：原来使用C或者Java的程序员在转而使用C++之后，会对for循环中使用!=而不是<进行判断有些奇怪。原因和C++的程序员更愿意使用迭代器而非下标的原因一样：因为这种编程风格在标准库提供的所有容器上都有效。只有一部分标准库类型有下标运算符，而且并不是所有容器的迭代器都定义了<>运算符。但是所有标准库容器的迭代器都定义了==和!=。


### 读取数量不定的输入数据

> example: exercise1-16.cpp

核心思想：不断循环，直到没有新的输入为止

**NOTE** 用istream对象作为条件时，其效果时检测流的状态。
         如果流时有效的，那么检测成功，返回true
         如果遇到文件结束符(end-of-file)，或遇到一个无效输入时（例如输入的不是整数），istream的对象的状态就会变为无效。返回false。

**NOTE** 在windows系统中指出文件结束，是输入Ctrl+Z+Enter.
         在UNIX和Mac OS X系统中，输入Ctrl+D


## 分支结构

### if 语句

> example: if_statement.cpp

NOTE: 这个程序有个致命的缺点，就是如果重复的数据是错开的(如：1, 2, 2, 3, 2), 那么程序就会把前后的两组2分开计算，比如(2 times 2, 1 times 1, 1 times 2)

改进过的程序：
> example: if_stm_improved.cpp (未完成)

这种稍微复杂的嵌套需要花一些时间理解了。
