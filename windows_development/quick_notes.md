# quick notes

## MessageBox()

是众多API中的一个，用于弹出一个指定风格的对话框，其原型为:
```int WINAPI MessageBox( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType );```

* WINAPI为宏定义```#define WINAPI _stdcall```，表示函数调用方式，返回按下的按钮，IDOK = 1, IDCANCEL = 2
* hWnd: 该消息框的父窗口句柄，如果此参数为NULL，则该消息框没有父窗口
* lpText: 消息框的内容 ```typedef CONST CHAR* LPCSTR```
* lpCaption: 消息框的标题
* uType: 对话框的按钮样式和图标

uType支持的按钮样式：

|        按钮         |                  含义                  |
| :-----------------: | :------------------------------------: |
|        MB_OK        |     默认值，有一个“确认”按钮在里面     |
|      MB_YESNO       |       有“是”和“否”两个按钮在里面       |
| MB_ABORTRETRYIGNORE | 有“中止”，“重试”和“跳过”三个按钮在里面 |
|   MB_YESNOCANCEL    |   有“是”，“否”和“取消”三个按钮在里面   |
|   MB_RETRYCANCEL    |     有“重试”和“取消”两个按钮在里面     |
|     MB_OKCANCEL     |     有“确定”和“取消”两个按钮在里面     |

这些按钮都是宏定义：
```
#define MB_OK                 0x00000000L
#define MB_OKCANCEL           0x00000001L
#define MB_ABORTRETRYIGNORE   0x00000002L
#define MB_YESNOCANCEL        0x00000003L
#define MB_YESNO              0x00000004L
#define MB_RETRYCANCEL        0x00000005L
```
你也可以尝试用数字来表示按钮，例如：
```
MessageBox(NULL, TEXT("Hello World!"), TEXT("Welcome"), 1);
```
也会生成与上面相同的对话框。

除了按钮，uType 还支持图标（图标对用户有提醒作用）：
|        图标        |                       含义                        |
| :----------------: | :-----------------------------------------------: |
| MB_ICONEXCLAMATION |             一个惊叹号出现在消息框：              |
|   MB_ICONWARNING   |          一个惊叹号出现在消息框（同上）           |
| MB_ICONINFORMATION |    一个圆圈中小写字母i组成的图标出现在消息框：    |
|  MB_ICONASTERISK   | 一个圆圈中小写字母i组成的图标出现在消息框（同上） |
|  MB_ICONQUESTION   |          一个问题标记图标出现在消息框：           |
|    MB_ICONSTOP     |          一个停止消息图标出现在消息框：           |
|    MB_ICONERROR    |       一个停止消息图标出现在消息框（同上）        |
|    MB_ICONHAND     |       一个停止消息图标出现在消息框（同上）        |

这些图标也都是宏定义：
```
#define MB_ICONHAND           0x00000010L
#define MB_ICONQUESTION       0x00000020L
#define MB_ICONEXCLAMATION    0x00000030L
#define MB_ICONASTERISK       0x00000040L
```
如果希望同时定义按钮和图标的样式，可以使用或运算|，例如：
```
MessageBox(
    NULL,
    TEXT("你好，欢迎来到C语言中文网！"),
    TEXT("Welcome"),
    MB_OKCANCEL | MB_ICONINFORMATION
);
```

大家有没有发现，按钮都是用十六进制的第1位（二进制前4位）来表示，图标都是使用十六进制第2位（二进制第5~8位）来表示，进行或运算，每个位都不会改变。

Windows 通过检测第1位的值来确定按钮的样式，检测第2位的值来确定图标样式。

再看来一下MessageBox() 的返回值。

MessageBox() 返回被按下的按钮，以数字表示，这些数字都被定义成了宏，如下所示：
|  返回值  |         含义         |
| :------: | :------------------: |
|   IDOK   | 用户按下了“确认”按钮 |
| IDCANCEL | 用户按下了“取消”按钮 |
| IDABORT  | 用户按下了“中止”按钮 |
| IDRETRY  | 用户按下了“重试”按钮 |
| IDIGNORE | 用户按下了“忽略”按钮 |
|  IDYES   |  用户按下了“是”按钮  |
|   IDNO   |  用户按下了“否”按钮  |

对应的宏定义为：
```
#define IDOK       1
#define IDCANCEL   2
#define IDABORT    3
#define IDRETRY    4
#define IDIGNORE   5
#define IDYES      6
#define IDNO       7
```

## Message

在一般的编程中，我们都是通过 API 函数来调用系统功能，让操作系统来帮我们完成很多工作，例如调用 CreateFile() 函数，操作系统会帮我们创建一个文件，而不需要我们参与任何工作，非常方便。

反过来，操作系统也会“偷懒”，会调用我们程序中的函数，让我们自己处理某些事情。例如用户敲击键盘，操作系统会首先收到通知，但它并不会处理，而是调用程序中的函数，告诉程序用户敲击了键盘，你自己处理好了；如果程序不处理，操作系统才会进行默认的操作。

当然，这不能理解为操作系统“偷懒”，而是给我们一个机会，让我们自行处理某些事情，从而使程序更加灵活和健壮，也让程序员有了更多发挥的空间。

用户敲击键盘、点击鼠标、拖动窗口、选择菜单、输入文字等所有的操作都称为事件(Event)。这与我们平时理解的“事件”是类似的，都表示发生了某些情况，好的或者坏的。

当有事件发生时，Windows 会生成一条消息(Message)，告诉程序发生了什么事情。这与我们平时理解的“消息”是类似，都表示一种传递信息的载体。

那么，Windows 是如何通过消息将发生的事件通知给应用程序的呢？

每当事件发生时，Windows 会生成一条消息，并放到一个由系统维护的队列中。然后，程序会自己从这个队列中获取消息并分析，调用事件处理函数（处理事件的代码也就在这个函数中），对用户的操作进行响应。
> 队列是一种先进先出的数据结构，不明白的请自行Google或百度。
注意：Windows 向队列中分派消息和应用程序从队列中获取消息并不是同步的，Windows 不管队列中有没有消息，不管应用程序有没有处理完毕，只要有事件发生，就会将消息丢进队列，什么时候处理完毕是应用程序的事。

可见，消息是连接 Windows 和应用程序的纽带，Windows 通过消息告诉应用程序发生了什么，应用程序通过消息知道该做什么。

### 消息结构体

消息其实是一个结构体，名字为 MSG，定义为：
```
typedef struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
} MSG;
```
Windows 向队列中投递消息，其实就是将一个类型为 MSG 的结构体变量丢进队列。

MSG 结构体中各成员变量的含义如下：
1) hwnd表示消息所属的窗口。用户一般是在程序的窗口下进行操作，所以一个消息一般都是与某个窗口相关联的。例如在某个活动窗口中按下鼠标左键，产生的按键消息就是发给该窗口的。

2) message表示消息类型，是一个数值。在Windows中，消息是由一个数值来表示的，不同类型的消息对应不同的数值。但是由于数值不便于记忆，所以Windows将消息对应的数值定义为WM_XXX宏（WM是Window Message的缩写）的形式，XXX 对应某种消息的英文拼写的大写形式。例如，鼠标左键按下消息是WM_LBUTTONDOWN，键盘按下消息是WM_KEYDOWN，字符消息是WM_CHAR，等等。在程序中我们通常都是以WM_XXX宏的形式来使用消息的。

3) 第三、第四个成员变量wParam和lParam，用于指定消息的附加信息。例如，当我们收到一个字符消息的时候，message成员变量的值就是WM_CHAR，但用户到底输入的是什么字符，那么就由wParam和lParam来说明。wParam、lParam表示的信息随消息的不同而不同。

4) 最后两个变量分别表示消息投递到消息队列中的时间和鼠标的当前位置。


## 完整的windows程序框架

我们通常所说的窗口包含最大化、最小化、关闭按钮，也包含菜单、单选框、图像等各种控件。

一个完整的Windows程序框架：
```
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow
){
    static TCHAR szClassName[] = TEXT("HelloWin");  //窗口类名
    HWND     hwnd;  //窗口句柄
    MSG      msg;  //消息
    WNDCLASS wndclass;  //窗口类

    /**********第①步：注册窗口类**********/
    //为窗口类的各个字段赋值
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //窗口风格
    wndclass.lpfnWndProc  = WndProc;  //窗口过程
    wndclass.cbClsExtra   = 0;  //暂时不需要理解
    wndclass.cbWndExtra   = 0;  //暂时不需要理解
    wndclass.hInstance    = hInstance;  //当前窗口句柄
    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //窗口图标
    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //鼠标样式
    wndclass.hbrBackground= (HBRUSH) GetStockObject (WHITE_BRUSH);  //窗口背景画刷
    wndclass.lpszMenuName = NULL ;  //窗口菜单
    wndclass.lpszClassName= szClassName;  //窗口类名

    //注册窗口
    RegisterClass(&wndclass);

    /*****第②步：创建窗口(并让窗口显示出来)*****/
    hwnd = CreateWindow(
        szClassName,  //窗口类的名字
        TEXT("Welcome"),  //窗口标题（出现在标题栏）
        WS_OVERLAPPEDWINDOW,  //窗口风格
        CW_USEDEFAULT,  //初始化时x轴的位置
        CW_USEDEFAULT,  //初始化时y轴的位置
        500,  //窗口宽度
        300,  //窗口高度
        NULL,  //父窗口句柄
        NULL,  //窗口菜单句柄
        hInstance,  //当前窗口的句柄
        NULL  //不使用该值
    );

    //显示窗口
    ShowWindow (hwnd, iCmdShow);
    //更新（绘制）窗口
    UpdateWindow (hwnd);

    /**********第③步：消息循环**********/
    while( GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);  //翻译消息
        DispatchMessage (&msg);  //分派消息
    }

    return msg.wParam;
}

/**********第④步：窗口过程**********/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    HDC         hdc;  //设备环境句柄
    PAINTSTRUCT ps;
    RECT        rect;

    switch (message){
        //窗口绘制消息
        case WM_PAINT:
            hdc = BeginPaint (hwnd, &ps) ;
            GetClientRect (hwnd, &rect) ;
            DrawText(
                hdc,
                TEXT("你好，欢迎来到C语言中文网"),
                -1,
                &rect,
                DT_SINGLELINE | DT_CENTER | DT_VCENTER
            );
            EndPaint (hwnd, &ps) ;
            return 0 ;

        //窗口销毁消息
        case WM_DESTROY:
            PostQuitMessage(0) ;
            return 0 ;
    }
    return DefWindowProc(hwnd, message, wParam, lParam) ;
}
```

## 窗口类

在Windows中，调用 CreateWindow() 函数可以创建一个窗口。窗口有很多属性，比如大小、位置、标题、背景颜色、鼠标样式、图标等，在创建窗口时都需要指定。这些属性比较多，超过10个，但是有一部分是通用的，不同的窗口，它们的值一般相同，Windows将这些通用的属性抽取出来，用一个结构体表示

对窗口类内每一个字段的简单说明
|     字段      |                                        说明                                         |
| :-----------: | :---------------------------------------------------------------------------------: |
|     style     |       窗口风格。常用的取值为CS_HREDRAW 或 CS_VREDRAW，文字始终处于窗口中间。        |
|  lpfnWndProc  |                           窗口处理过程，下面会详细讲解。                            |
|   hInstance   |                                   当前窗口句柄。                                    |
|     hIcon     |  窗口图标。也就是程序运行时在左上角和任务栏看到的图标，需要通过LoadIcon函数加载。   |
|    hCursor    |                       鼠标样式。需要通过LoadCursor函数加载。                        |
| hbrBackground |   窗口背景画刷。也就是窗口背景的填充颜色，后面我们会讲解画笔、画刷和画布的概念。    |
| lpszMenuName  | 窗口菜单。也就是标题栏下方看到的多种多样的菜单，上面的程序没有菜单，所以值为 NULL。 |
| lpszClassName |          窗口类的名字。每个窗口类的名字都是不同的，以便与其他窗口类区分。           |

### 注册窗口类

### 创建窗口

有了窗口类，就可以根据它来创建窗口了。创建窗口使用 CreateWindows() 函数，如下所示：
```
hwnd = CreateWindow(
    szClassName,  // 窗口类的名字
    TEXT("Welcome"),  //窗口标题（出现在标题栏）
    WS_OVERLAPPEDWINDOW,  //窗口风格
    CW_USEDEFAULT,  //初始化时窗口x轴坐标
    CW_USEDEFAULT,  //初始化时窗口y轴坐标
    500,  //窗口宽度
    300,  //窗口高度
    NULL,  //父窗口句柄。这里没有父窗口，所以为 NULL
    NULL,  //窗口菜单句柄。当前窗口没有菜单，所以为 NULL
    hInstance,  //当前窗口的句柄，通过 WinMain 函数传入。
    NULL  //不使用该值
);
```

几点说明：
1. CreateWindow 的第一个参数就是窗口类的名字，通过这个名字可以找到刚才注册的窗口类，然后再根据它来创建窗口。
2. 显示器上的坐标与数学中的不同，显示器的左上角是坐标原点，从原点向右是x轴，向下是y轴，都是正坐标，没有负数。
3. 参数 hInstance 是通过主函数 WinMain 传入的。

注意：通过 CreateWindows() 函数创建窗口后，仅仅是为窗口分配了内存空间，获得了句柄，但窗口并没有显示出来，所以还需要调用 ShowWindow() 函数来显示窗口。

而调用了 ShowWindow() 函数又仅仅是将窗口显示出来，但不会进行客户区的绘制，所以还需要调用 UpdateWindow() 函数，生成 VM_PAINT 消息，将客户区中的各种控件绘制出来。

至此，一个窗口的创建工作就已经完成了。窗口的各种属性，在窗口类和 CreateWindow() 函数的参数中都进行了说明。

### 进行消息循环

在 UpdateWindow 函数被调用之后，新建的窗口在屏幕中就可以显示了。此时，程序必须能够接受用户的键盘或鼠标事件，例如按下回车键、右击鼠标等。

Windows 会为每个应用程序维护一个消息队列，当有事件发生时，Windows会自动将这些事件转换为“消息”，并投递到消息队列。

在我们的程序中，可以通过一段“消息循环”代码来从消息队列中获取消息：
```
while( GetMessage(&msg, NULL, 0, 0) ){
    TranslateMessage(&msg);  //翻译消息
    DispatchMessage (&msg);  //分派消息
}
```
GetMessage 函数用来从消息队列中获取一条消息，并保存到 MSG 结构体变量中。
```BOOL GetMessage(LPMSG, HWND, UINT, UINT);```

注意：GetMessage 的返回值永远为非零值，**while 循环会一直进行下去**。如果队列中没有消息，GetMessage 函数会等待，直到有消息进入。

获取到消息后，需要调用 TranslateMessage 函数对消息进行转换（翻译），然后再调用 DispatchMessage 函数将消息传给窗口过程去处理（调用窗口过程）。

### 窗口过程

所谓窗口过程，就是处理窗口事件的函数，也就是上面代码中最后的 WndProc 函数。GetMessage 每获取到一条消息，最终都会丢给窗口过程去处理。

窗口过程有一个参数 message，会传入发生的事件类型，常用的有：
* WM_CREATE：窗口被创建。
* WM_PAINT：窗口需要更新或重绘。
* WM_WM_DESTROY：窗口被销毁（关闭）。

WM_CREATE 和 WM_DESTROY 很容易理解，WM_PAINT 将在下节中详细讲解，它非常重要，不理解 WM_PAINT 可以说就没有学会Windows编程。

不同的消息往往需要进行不同的处理，所以一般通过 switch case 语句来匹配。

注意：你可以对获取到的消息进行处理，加入自己的业务逻辑；也可以不处理，让Windows自己看着办（默认处理方式）。窗口过程最后一条语句：
```
return DefWindowProc(hwnd, message, wParam, lParam) ;
```
它的作用就是让Windows自己处理应用程序没有处理的消息，必须要有该语句。

> 窗口过程在窗口类中指明，然后就不用管了，不需要我们显式调用。