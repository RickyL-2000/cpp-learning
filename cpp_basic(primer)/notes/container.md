# 容器

## 容器库概览

容器操作

|    类型别名     |                      意义                      |
| :-------------: | :--------------------------------------------: |
|    iterator     |                     迭代器                     |
| const_iterator  |                只读的迭代器类型                |
|    size_type    | 无符号整数类型，足够保存此容器类型最大可能大小 |
| difference_type |      带符号整数类型，两个迭代器之间的距离      |
|   value_type    |                    元素类型                    |
|    reference    |    元素的左值类型：与value_type&含义相同(?)    |
| const_reference |                 const左值类型                  |

|     构造函数     |                           意义                            |
| :--------------: | :-------------------------------------------------------: |
|       C c;       |              默认构造函数，构造空容器(array)              |
|    C c1(c2);     |                      构造c2的拷贝c1                       |
|    C c(b, e);    | 构造c，将迭代器b和e指定的范围内的元素拷贝到c(array不支持) |
| C c{a, b, c...}; |                        列表初始化c                        |

|    赋值与swap     |            意义            |
| :---------------: | :------------------------: |
|      c1 = c2      | 将c1中的元素替换为c2中元素 |
| c1 = {a, b, c...} | 将c1中元素替换为列表中元素 |
|     a.swap(b)     |       交换a和b的元素       |
|    swap(a, b)     |            同上            |

|     大小     |               意义                |
| :----------: | :-------------------------------: |
|   c.size()   | c中元素的数目(不支持forward_list) |
| c.max_size() |      c可以保存的最大元素数目      |
|  c.empty()   |             是否为空              |

| 添/删元素(不适用于array) |             意义              |
| :----------------------: | :---------------------------: |
|      c.insert(args)      |     将args中的元素拷贝进c     |
|     c.emplace(inits)     | 使用inits构造c中的一个元素(?) |
|      c.erase(args)       |      删除args指定的元素       |
|        c.clear()         |  删除c中的所有元素，返回void  |

|  关系运算符  |              意义              |
| :----------: | :----------------------------: |
|    ==, !=    | 所有容器都支持相等(不等)运算符 |
| <, <=, >, >= | 关系运算符(无序关联容器不支持) |

|      获取迭代器      |                   意义                    |
| :------------------: | :---------------------------------------: |
|  c.begin(), c.end()  | 返回指向c的首元素和尾元素之后位置的迭代器 |
| c.cbegin(), c.cend() |            返回const_iterator             |

|   反向容器的额外成员   |                   意义                    |
| :--------------------: | :---------------------------------------: |
|    reverse_iterator    |          按逆序寻址元素的迭代器           |
| const_reverse_iterator |              只读逆序迭代器               |
|  c.rbegin(), c.rend()  | 返回指向c的尾元素和首元素之前位置的迭代器 |
| c.crbegin(), c.crend() |        返回const_reverse_iterator         |

**NOTE**: 关联容器不支持顺序容器的位置相关的操作。


## 顺序容器

顺序容器(sequential container)为程序员提供了控制元素存储和访问顺序的能力。

标准库中有很多顺序容器，所有顺序容器都提供了快速顺序访问元素的能力。但是，这些容器在以下方面都有不同的性能折中：
1. 向容器添加或从容器中删除元素的代价
2. 非顺序访问容器中元素的代价

顺序容器类型
|  container   |                        clarification                         |
| :----------: | :----------------------------------------------------------: |
|    vector    | 可变大小数组。支持快速随机访问。除尾部外插入删除元素可能很慢 |
|    deque     |     双端队列。支持快速随机访问。在头尾插入/删除速度很快      |
|     list     |    双向链表。只支持双向顺序访问。任何位置插入/删除都很快     |
| forward_list |         单向列表。只支持单项顺序访问。插入/删除很快          |
|    array     |      固定大小数组。支持快速随机访问。不能添加或删除元素      |
|    string    |            与vector相似的容器，但专门用于保存字符            |

除了array外，其他容器都提供高效、灵活的内存管理。

选择容器的基本原则
1. 除非有很好的理由，否则应使用vector
2. 如果程序有很多小的元素，且空间的额外开销很重要，则不要使用list或forward_list
3. 如果要求随机访问元素，应使用vector或deque
4. 如果程序只有在读取输入时才需要在容器中间插入元素，随后需要随机访问元素，则：
   1. 首先，确定是否真的需要在容器中间位置添加元素。可以先容易地向vector追加数据，然后再调用标准库的sort函数来重排容器中的元素，从而避免在中间位置添加元素。
   2. 如果必须在中间位置插入元素，考虑在输入阶段使用list，一旦输入完成，将list中的内容拷贝到一个vector中



#### 迭代器

与容器一样，迭代器有着公共的接口：如果一个迭代器提供某个操作，那么所有提供相同操作的迭代器对这个操作的实现方式都是相同的。

##### 迭代器范围

迭代器范围的概念是标准库的基础。

一个迭代器范围由一对迭代器表示：首元素和尾后元素，begin 和 end。 [begin, end)

1. 如果begin和end相等，则范围为空。
2. 如果begin和end不等，则范围至少包含一个元素

#### 容器类型成员

每个容器都定义了多个类型。比如：size_type, iterator, const_iterator。

大多数容器还提供反向迭代器。

剩下的就是类型别名，通过类型别名，可以在不了解容器中元素类型的情况下使用它。如果需要元素类型，可以使用容器的value_type。如果需要元素类型的一个引用，可以使用reference或者const_reference。


#### 容器定义和初始化

每个容器类型都定义了一个默认构造函数。除array之外，其他容器的默认构造函数都会创建一个指定类型的空容器，且都可以接受指定容器大小和元素初始值的参数。

容器定义和初始化
|    statements    |                          meanings                           |
| :--------------: | :---------------------------------------------------------: |
|       C c;       |   默认构造函数，构造空容器(若是array，则按默认方式初始化)   |
|    C c1(c2);     | 构造c2的拷贝c1（必须是相同类型，若是array，还必须有相同大小 |
|     C c1=c2      |                            同上                             |
|    C c(b, e);    |  构造c，将迭代器b和e指定的范围内的元素拷贝到c(array不支持)  |
| C c{a, b, c...}; |                         列表初始化c                         |
|     C seq(n)     |  seq包含n个元素并进行了值初始化，是透明的（string不透明）   |
|    C seq(n,t)    |                 seq包含n个初始化为值t的元素                 |



#### 赋值和swap

##### 使用assign

##### 使用swap

swap操作交换两个相同类型容器的内容。

    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1, svec2);


### 顺序容器操作

#### 向顺序容器添加元素

添加元素的操作(array不支持)
|      operations       |                           meanings                            |
| :-------------------: | :-----------------------------------------------------------: |
|    c.push_back(t)     |                 在c的尾部创建一个值为t的元素                  |
| c.emplace_back(args)  |                  在c的尾部由args创建一个元素                  |
|    c.push_front(t)    |                            同上上                             |
| c.emplace_front(args) |                            同上上                             |
|    c.insert(p, t)     |  在迭代器p的元素前创建一个元素t，返回指向新添加元素的迭代器   |
|   c.emplace(p,args)   |                     同上，由args创建元素                      |
|    c.insert(p,n,t)    | 在迭代器p之前插入n个元素值为t。返回新添加的第一个元素的迭代器 |
|    c.insert(p,b,e)    |   将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前   |
|    c.insert(p,il)     |                il是一个花括号包围的元素值列表                 |

**NOTE**：
1. forward_list有自己专有版本的insert和emplaces
2. forward_list不支持push_back和emplace_back
3. vector和string不支持push_front和emplace_front

#### 访问元素

在顺序容器中访问元素的操作
| operations |          meanings          |
| :--------: | :------------------------: |
|  c.back()  |    返回c中尾元素的引用     |
| c.front()  |    返回c中首元素的引用     |
|    c[n]    | 返回c中下标为n的元素的引用 |
|  c.at(n)   |            同上            |

**NOTE**：
1. at和下标操作只适用于string, vector, deque, array
2. back不适用于forward_list


#### 删除元素

顺序容器的删除操作
|  operations   |                           meanings                            |
| :-----------: | :-----------------------------------------------------------: |
| c.pop_back()  |                         删除c中尾元素                         |
| c.pop_front() |                         删除c中首元素                         |
|  c.erase(p)   | 删除迭代器p所制定的元素，返回一个指向被删元素之后元素的迭代器 |
| c.erase(b,e)  | 删除迭代器b和e所指定范围内的元素，返回最后被删元素后的迭代器  |
|   c.clear()   |                       删除c中的所有元素                       |

#### 特殊的forward_list操作(?)

#### 改变容器大小

顺序容器大小操作（不适用于array）
|  operations   |            meanings             |
| :-----------: | :-----------------------------: |
|  c.resize(n)  |      调整c的大小为n个元素       |
| c.resize(n,t) | 同上，新添加的元素被初始化为值t |


#### 容器操作可能导致迭代器失效

#### vector对象是如何增长的

vector和string类型提供了一些成员函数，允许我们与它的实现中内存分配部分互动

容器大小管理操作
|    operations     |                 meanings                  |
| :---------------: | :---------------------------------------: |
| c.shrink_to_fit() |   请将capacity()减少为与size()相同大小    |
|   c.capacity()    | 不重新分配内存空间的话，c可以保存多少元素 |
|   c.reserve(n)    |      分配至少能容纳n个元素的内存空间      |

**NOTE**：
1. shrink_to_fit只适用于vector、string和deque
2. capacity和reserve只适用于vector和string


### 额外的string操作(?)

略


### 容器适配器(?????)



### 标准库类型vector

标准库类型vector表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引，索引用于访问对象。所以vector也常被称作容器(container)

vector是一个封装了动态大小数组的顺序容器(sequence container)，是一个能够存放任意类型的动态数组。

vector被包含在头文件<vector>的标准库中，可以用using声明进行简化：

    #include <vector>
    using std::vector;

C++语言既有类模板(class template)，也有函数模板，其中vector是一个类模板。模板本身不是类或函数，相反可以将模板看作编译器生成类或者函数编写的一份说明。编译器根据模板创建类或者函数的过程称为实例化(instantiation)，当使用模板时，需要指出编译器应把类或者函数实例化成何种类型。

对于类模板来说，需要提供一些额外信息来指定模板到底实例化成什么样的类。提供信息的方式：在模板名字后面跟一对尖括号，在括号内放上信息。example:

    vector<int> ivec;              //ivec保存int类型的对象
    vector<Sales_item> Sales_vec;  //保存Sales_item类型的对象
    vector<vector<string>> file;   //该向量的元素是vector对象

**NOTE**：
1. 因为引用不是对象，所以不存在包含引用的vector。
2. 早期版本的C++标准中，如果vector的元素还是vector(或者其他模板类型)，则其定义的形式有所不同，必须在外层vector对象的右尖括号和其元素类型之间添加一个空格:

        vector<vector<int> > file;


#### 定义和初始化vector对象

初始化vector对象的方法：

    vector<T> v1;                       //空vector，它潜在的元素是T类型的，执行默认初始化
    vector<T> v2(v1);                   //v2中包含有v1所有元素的副本
    vector<T> v2 = v1;                  //同上
    vector<T> v3(n, val);               //包含了n个重复的元素，每个元素的值都是val
    vector<T> v4(n);                    //包含了n个重复地执行了*值初始化的*对象
    vector<T> v5{a, b, c...}            //列表初始化，包含了初始值个数的元素，每个元素被赋予相应的初始值
    vector<T> v5 = {a, b, c...}         //同上

**NOTE**：
1. 拷贝vector对象的时候其类型必须相同
2. 在大多数情况下C++提供的几种初始化方式可以相互等价地使用，不过并非一直如此。几种特殊情况：
   1. 使用拷贝初始化时(即使用=时)，只能提供一个初始值
   2. 如果提供的是一个类内初始值，则只能使用拷贝初始化或使用花括号形式的初始化(?)
   3. 如果提供的是初始元素值的列表，只能把初始值都放在花括号里进行列表初始化，而不能放在圆括号里
3. 通常情况下，可以只提供vector对象容纳的元素数量而不用略去初始值。此时库会创建一个值初始化的(value-initialized)元素初值，并把它赋给所有元素。这个初值由vector对象中元素的类型决定。比如，若vector对象的元素是内置类型，比如int，则元素初始值自动设为0。如果是某种类类型，比如string，则元素由类默认初始化(比如空string对象)。对这种初始化的方式有两个特殊限制：
   1. 有些类要求明确地提供初始值。对这种类型的对象来说，只提供元素的数量而不设定初始值无法完成初始化工作
   2. 如果只提供了元素的数量而没有设定初始值，只能使用直接初始化。
   
        vector<int> ivec(10);     //10个元素，每个都初始化为0
        vector<string> svec(10);  //空string对象
        vector<int> vi = 10;      
        /*错误，必须使用直接初始化的形式指定向量大小。因为我们的本意是想创建含有10个值初始化了的元素的vector对象，而非把数字10“拷贝”到vector中。所以不应该用拷贝初始化


#### vector操作

> example: score.cpp  用于计算每个分数段的人数(很像python中的dict计数)

|    operation    |        meaning        |
| :-------------: | :-------------------: |
|    v.empty()    |       返回真假        |
|    v.size()     |       返回个数        |
|      v[n]       | 返回n位置上元素的引用 |
|     v1 = v2     |       拷贝替换        |
| v1 = {a,b,c...} |       拷贝替换        |
|    v1 == v2     |       完全相同        |
|    v1 != v2     |         不同          |
|  <. <=, >, >=   |  以字典顺序进行比较   |
| v.push_back(t)  |    在尾端添加一个t    |


* 添加元素 push_back

对于一些vector内元素繁多且各不相同、直到运行时才能知道vector对象中元素的确切个数的情况，最好的方法是一开始声明一个空vector，然后依次往里添加元素。

example:
    
    string word;
    vector<string> text;     // 空vector对象
    while (cin >> word) {
        text.push_back (word);
    }

**NOTE**：
1. 既然vector对象能够高效地增长，那么在定义vector对象的时候设定其大小就没什么必要了，事实上这么做可能性能更差。
2. **不能用下标形式添加元素！**对于下面这个例子，ivec是一个空vector，根本不包含任何元素，当然也就不能通过下标去访问任何元素！正确的做法是用push_back。

        vector<int> ivec;
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
            ivec[ix] = ix;  //严重错误
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
            ivec.push_back(ix);   //正确


* size()和empty()
  
功能与string的成员函数完全一致。size()返回vector对象中元素的个数，返回值的类型是由vector定义的size_type类型

**NOTE**：要使用size_type，需要首先指定它是由哪种类型定义的。

    vector<int>::size_type    //正确
    vector::size_type         //错误


* 下标操作[]

**NOTE**：
1. **不能用下标形式添加元素！**对于下面这个例子，ivec是一个空vector，根本不包含任何元素，当然也就不能通过下标去访问任何元素！正确的做法是用push_back。

        vector<int> ivec;
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix) //(感觉用int ix也没错？
            ivec[ix] = ix;  //严重错误
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
            ivec.push_back(ix);   //正确
2. 只能对确定已存在的元素执行下标操作。试图用下标的形式去访问一个不存在的元素将引发错误，不过这种错误不会被编译器发现，而是在运行时产生一个不可预知的值。所谓缓冲区溢出(buffer overflow)指的就是这类错误。
3. 标准库类型限定使用的下标必须是无符号类型。


#### 迭代器iterator

所有标准库容器都可以使用迭代器，但是其中只有少数几种才同时支持下标运算符。

和指针不一样的是，获取迭代器不是使用取地址符，有迭代器的类型同时拥有返回迭代器的成员。比如，这些类型都拥有名为begin和end的成员。

begin()成员负责返回指向第一个元素的迭代器，end()成员则负责返回指向容器"尾元素的下一位置(one past the end)"的迭代器，也就是说，该迭代器指示的是容器的一个本不存在的"尾后(off the end)"元素。这样的迭代器没什么实际含义，仅是个标记而已，表示我们已经处理完了容器中的所有元素。

**NOTE**：
1. 如果容器为空，begin和end返回的是同一个迭代器，都是尾后迭代器。
2. C++貌似并不关心迭代器的类型，只需要在iter前面注明auto就可以了。但是iter可以递增或者递减，说明有整数的性质。

example:

    auto b = v.begin(), e = v.end();
    //由编译器决定b和e的类型


##### 迭代器运算符

|    operator    |                         meaning                          |
| :------------: | :------------------------------------------------------: |
|     *iter      |               返回迭代器iter所指元素的引用               |
|   iter->mem    | 解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem |
|     ++iter     |                      指向下一个元素                      |
|     --iter     |                      指向上一个元素                      |
| iter1 == iter2 |                           相等                           |
| iter1 != iter2 |                           不等                           |

example: 利用迭代器把string对象的第一个字母改为了大写形式

    string s("some string");
    if (s.begin() != s.end()) {   //确保s非空
        auto it = s.begin();
        *it = toupper(*it);
    }

example: 利用迭代器和递增运算符把string对象的第一个字母改为了大写形式

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);

* begin()和end()运算符

begin和end返回的具体类型由对象是否是常量决定，如果对象是常量，begin和end返回const_iterator，否则是iterator。然而，为了便于专门得到const_iterator类型的返回值，C++11新标准引入了两个新函数：cbegin()和cend()。example:

    auto it3 = v.cbegin(); // it3的类型是vector<int>::const_iterator

* 结合解引用和成员访问操作 箭头运算符

如果解引用迭代器所指的对象恰好是类，就有可能进一步访问它的成员。为了简化这一表达式，C++定义了箭头运算符(->)，example:
    
    *it.empty()    //错误，试图访问it的名为empty的成员，但是it是一个迭代器没有成员
    (*it).empty()  //解引用it，然后调用结果对象的empty成员
    it -> empty()  //与上式相同

    //依次输出text的每一行直至遇到第一个空白为止
    for (auto it = text.cbegin(); it != text.cend() && ！it->empty(); ++it)
        cout << *it << endl;


##### 迭代器类型

一般来说我们无需知道迭代器的精确类型(就像string和vector的size_type成员一样)。而实际上，那些拥有迭代器的标准库类型使用iterator和const_iterator来表示迭代器的类型：

    vector<int>::iterator it;  // it能读写vector<int>的元素
    string::iterator it2;      // it2能读写string对象中的字符
    
    vector<int>::const_iterator it3;  // it3只能读取但不能修改它所指的元素值
    string::const_iterator it4;       // it4只能读取但不能修改它所指的元素值


##### 迭代器的限制

1. 不能在范围for循环中向vector对象添加元素。
2. 任何一种改变vector对象容量的操作，都会使vector对象的迭代器失效。
   

**NOTE**：但凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素。


##### 使用迭代器运算

**vector和string迭代器支持的运算**
|   operation   |             meaning              |
| :-----------: | :------------------------------: |
|   iter + n    |      指向容器内的某一个元素      |
|   iter - n    |               同上               |
|  iter1 += n   |     迭代器加法的复合赋值语句     |
|  iter1 -= n   |     迭代器减法的复合赋值语句     |
| iter1 - iter2 | 同一个容器中两个迭代器之间的距离 |
|   <,<=,>,>=   |        迭代器的关系运算符        |

**NOTE**：注意！两个迭代器不能相加！


使用迭代器运算的一个经典算法是二分搜索。example:

    // text必须有序
    // beg和end表示我们搜索的范围
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg)/2; //因为迭代器没有加法，所以不能(end+beg)/2
    while (mid != end && *mid != sought) {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg)/2;
    }






## 关联容器

关联容器都支持本md开始时的容器操作，除了顺序容器的位置相关的操作。

关联容器类型
1. 按关键字有序保存元素
| containers |       clarifications        |
| :--------: | :-------------------------: |
|    map     |  关联数组：保存key-value对  |
|    set     | 关键字即值，只保存key的容器 |
|  multimap  |    关键字可重复出现的map    |
|  multiset  |    关键字可重复出现的set    |

2. 无序集合
|     containers     |   clarifications    |
| :----------------: | :-----------------: |
|   unordered_map    | 用散列函数组织的map |
|   unordered_set    | 用散列函数组织的set |
| unordered_multimap |       可重复        |
| unordered_multiset |       可重复        |

类型map和multimap定义在头文件< map >中； 
set和multiset定义在头文件<set>中；
无序容器则定义在头文件unordered_map和unordered_set中。


### 定义关联容器

初始化一个map时，必须提供关键字类型和值类型。但是可以默认初始化，也可以用花括号将每个关键字-值对包围着初始化：

    map<string, size_t> word_count;
    map<string, string> authors = { {"Joyce", "James"},
                                    {"Austen", "Jane"},
                                    {"Dickens", "Charles"} };  // {key, value}

初始化set就不需要构建键值对。

一个map或set中的关键字必须是唯一的。即，对于一个给定的关键字，只能由一个元素的关键字等于它。而容器multimap和multiset没有此限制。举例：用vector保存20个元素：0到9每个整数有两个拷贝：

    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.cbegin(), ivec.cend());        // C c(b, e) 构造函数
    multiset<int> miset(ivec.cbegin(), ivec.cend());


#### 关键字类型的要求 (?)

关联容器对其关键字类型有一些限制。

##### 对有序关联容器

关键字必须定义元素比较的方法。

默认情况下，标准库使用关键字类型的 < 运算符来比较两个关键字。在集合类型中，关键字类型就是元素类型；在映射类型中，关键字类型是元素的第一部分的类型。

可以向一个算法提供给我们自己定义的比较操作(泛型算法)，与之类似，也可以提供自己定义的操作来代替关键字上的 < 运算符。所提供的操作必须在关键字类型上定义一个严格弱序(strict weak orering)。可以将严格弱序看作“小于等于”。


#### pair 类型

pair是定义在头文件utility中的标准库类型

一个pair保存两个数据成员。类似容器，pair是一个用来生成特定类型的模板。当创建一个pair时，我们必须提供两个类型名：

    pair<string, string> anon;
    pair<string, size_t> word_count;
    pair<string, vector<int>> line;
    // pair 的默认构造函数对数据成员进行值初始化

    pair<string, string> author{"James", "Joyce"};


### 使用关联容器

example: 用map实现单词计数程序

    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word]; //如果有此关键字，+1；如果没有，默认初始化为0再+1
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
            << (w.second > 1) ? " times" : " time" << endl;

example: 用set实现忽略特定单词程序

    map<string, size_t> word_count;
    set<string> exclude = {"The", "But","And","Or","An","A",
                            "the","but","and","or","an","a"};
    string word;
    while (cin >> word) {
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }

find()函数返回一个迭代器。如果给定关键字在set中，迭代器指向该关键字。否则，find()返回尾后迭代器。