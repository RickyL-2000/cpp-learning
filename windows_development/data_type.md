# Data Type

Windows使用typedef或#define定了很多新的数据类型，前面几节中我们已经领略到了。它们虽然多，但是都有规律可循，很多都是对C/C++中数据类型的简单加工，而且很容易“见名知意”。要想学习Windows编程，必须要了解常用的数据类型。

这些数据类型在windows.h头文件中定义：
```
typedef int                 INT;       /* 整形 */
typedef unsigned int        UINT;      /* 无符号整形 */
typedef unsigned int        *PUINT;    /* 无符号整形指针 */
typedef int                 BOOL;      /* 布尔类型 */
typedef unsigned char       BYTE;      /* 字节 */
typedef unsigned short      WORD;      /* WORD (无符号短整型) */
typedef unsigned long       DWORD;     /* DOUBLE WORD (无符号长整形)*/
typedef float               FLOAT;     /* 浮点型 */
typedef FLOAT               *PFLOAT;   /* 指向float类型指针 */
typedef BOOL near           *PBOOL;    /* 指向布尔类型指针 */
typedef BOOL far            *LPBOOL;
typedef BYTE near           *PBYTE;    /* 指向字节类型指针 */
typedef BYTE far            *LPBYTE;
typedef int near            *PINT;     /* 整形指针 */
typedef int far             *LPINT;
typedef WORD near           *PWORD;    /* 指向WORD类型的指针 */
typedef WORD far            *LPWORD;
typedef long far            *LPLONG;   /* 指向长整形的指针 */
typedef DWORD near          *PDWORD;   /* 指向DWORD类型的指针 */
typedef DWORD far           *LPDWORD;
typedef void far            *LPVOID;   /* 指向void类型的指针 */
typedef CONST void far      *LPCVOID;  /* 指向void类型的常指针 */
```

简单说下，大部分类型都没有什么离奇的地方，可能很多读者会对那个 far 和 near 觉得有疑问，实际上 F12 查看定义会发现他们就定义上方：
#define far
#define near
看到这里你是否还是有疑问？其实，这个 far 和 near 只是用来标识变量的新旧的（预处理阶段 far 和 near 会被替换成空字符串）。 例如 PINT 和 LPINT 实际上都是 int *，只不过一个是老式写法，一个是新式写法，这都是为了兼容问题。

简单的看下这些数据类型，就可以总结出：但凡是以 “P” 开头的都是指针（pointer）类型（"LP"是老式写法）。撇开这些不谈，那么实际上这些 Windows API 常用的一些数据结构跟我们原本所学的 C/C++ 变量差别就是一个 typedef 而已，基础好的熟悉一下就行了。不过，也不要想得这么简单，Windows 编程还有一些比较复杂的类型比如 HWND、HANDLE 等。