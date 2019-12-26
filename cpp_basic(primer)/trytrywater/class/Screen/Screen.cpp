#include "Screen.h"
#include <string>

void Screen::some_member() const {
    ++access_ctr;   // 保存一个计数值，用于记录成员函数被调用的次数
}

inline Screen& Screen::set(char c) {    // 返回一个引用，否则就是返回一个拷贝
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch;
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}