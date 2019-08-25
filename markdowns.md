# 随记

## C 结构体、C++ 结构体、C++ 类的区别

参考：[C结构体、C++结构体、C++类的区别](https://www.cnblogs.com/cthon/p/9170596.html)

### C 和 C++ 中结构体的不同区别

1. C语言中的结构体不能为空，否则会报错
1>d:\myproject\visual studio 2013\projects\myc++\main.c(71): error C2016: C 要求一个结构或联合至少有一个成员
2. C语言中的结构体只涉及到数据结构，而不涉及到算法，也就是说在C中数据结构和算法是分离的。换句话说就是C语言中的结构体只能定义成员变量，但是不能定义成员函数。然而在C++中既可以定义成员变量又可以定义成员函数， C++中的结构体和类体现了数据结构和算法的结合。不过虽然C语言的结构体中不能定义成员函数，但是却可以定义函数指针，不过函数指针本质上不是函数而是指针，所以总的来说C语言中的结构体只是一个复杂数据类型 ，只能定义成员变量，不能定义成员函数，不能用于面向对象编程。
   example:

        int My_Add(int a, int b){
            return a + b;
        }
        int My_Sub(int a, int b){
            return a - b;
        }
        struct CTest{
            int(*Add)(int, int); //函数指针
            int(*Sub)(int, int);
        };
        
        int main(){
            struct CTest test;
            int ret = 0;
            test.Add = My_Add;
            test.Sub = My_Sub;
            ret = test.Add(3, 5);
            printf("%d", ret);
        }
3. 总的来说就是在C语言中结构体变量定义的时候，若为 struct 结构体名变量名定义的时候，struct不能省略。但是在C++之中则可以省略struct。
   example:

        struct CTest {
            char ch;
            int num;
        };
        int main() {
            CTest test;
            test.num = 1;
            printf("%d", test.num);
        }
        /* 以上代码在 C 语言中是便宜不过去的，原因提示未定义标识符 CTest。

### C++ 中的结构体与类的区别

先来说说C++中两者的相同之处： 结构体中也可以包含函数；也可以定义public、private、protected数据成员；定义了结构体之后，可以用结构体名来创建对象。也就是说在C++当中，结构体中可以有成员变量，可以有成员函数，可以从别的类继承，也可以被别的类继承，可以有虚函数。总的一句话：class和struct的语法基本相同，从声明到使用，都很相似，但是struct的约束要比class多，理论上，struct能做到的class都能做到，但class能做到的stuct却不一定做的到。

再来说说两者的区别：对于成员访问权限以及继承方式，class中默认的是private，而struct中则是public。class还可以用于表示模板类型，struct则不行。
注意struct是可以继承与被继承的，这一点有的人可能忽略了，来看一下struct中的继承与被继承：

    struct A{
    public:
        A(){};
        virtual void Dynamic(){    //TODO: 这是个啥子？
            cout << "A" << endl;
        }
    protected:
        void fun();
    private:
        int m_Data;
    };
    
    struct B:public A{
    public:
        virtual void Dynamic(){
            cout << "B" << endl;
        }
    };
    int main(){
        A * pa = new B;
        pa->Dynamic();
    }
    /* 编译完全没有问题


### C 和 C++ 在申请结构体时的不同

参考：[定义一个结构体指针需要分配存储空间？](https://blog.csdn.net/dreamzuora/article/details/54377197)

[定义结构体指针时，有没有同时分配存储空间](http://bbs.pfan.cn/post-284115.html)

所谓的分配空间，就是对指针赋值，把一个变量的地址赋值给一个指针。

很明显三楼和四楼讲的有点底层了，不过其他楼层说的很明白，首先只是分配了指针本身的存储空间，指针指针还没有被赋值，通过new或者malloc()语句是为了给结构体变量分配内存空间，即为指针赋值，即指针指向的内容的信息，便有了指针指向的数据内容和空间。


## 关于输入输出的那些事儿

### 如何读入多行并将每行的数据存入不同的数组

```
// 以存入两行数据为例
int main() {
    int num[100], location[100], *p = num, *q = location;
    // location 存放换行位置
    char temp;   // 识别输入的回车
    while(1) {
        scanf("%d%c", p, &temp);
        if (*p == -1)    // 判断是否为结束标志
            break;
        if (temp == '\n')
            *q++ = p - num + 1;
        p++;
    }
    *p = '\0';  // 将数组给定结束标记
}