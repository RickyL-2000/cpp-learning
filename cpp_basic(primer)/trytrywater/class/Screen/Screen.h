#include <string>
#include <vector>

class Screen{
    friend class Window_mgr;

public:
    typedef std::string::size_type pos;
    // or: using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c): 
            height(ht), width(wd), contents(ht * wd, c) {}
    char get() const                    // 读取光标处的字符
        { return contents[cursor];}     // 隐式inline
    inline char get(pos ht, pos wd) const; // 显式inline (???)
    Screen& move(pos r, pos c);            // 能在之后被设为inline (???)
    Screen& set(char);
    Screen& set(pos, pos, char);

    /* ???? */
    Screen& display(std::ostream &os) {do_display(os); return *this;}
    const Screen& display(std::ostream &os) const
                                        {do_display(os); return *this;}

    void some_member() const;   // 追踪每个成员函数被调用了多少次

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    // 该函数负责显示Screen的内容
    void do_display(std::ostream &os) const {os << contents;}

    mutable size_t access_ctr;  // 即使在一个const对象内也能被修改
};


/* 窗口管理类，用于表示显示器上的一组Screen */
class Window_mgr {
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    // 默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

class Link_screen {
    Screen window;
    Link_screen* next;
    Link_screen* prev;
}