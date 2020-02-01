#pragma once
#include <graphics.h>
#include <Windows.h>
// 引用该库才能使用 TransparentBlt 函数
#pragma comment( lib, "MSIMG32.LIB")


// 支持透明绘制的putimage，
// pDestImg为空表示将pSrcImg画到屏幕上，否则画到pDestImg上
// 透明色为粉色，所以素材本身如果出现粉色需要处理，否则不想透明的地方也透明了
// 资源需要使用bmp格式，因为jpg会优化像素，导致某些透明像素点不够“粉”
inline void putimagex(int destX, int destY, int destWidth, int destHeight, IMAGE *pSrcImg, int srcX, int srcY, IMAGE *pDestImg = NULL)
{
	if (pSrcImg == NULL)
	{
		return;
	}
	// 获取绘图窗口和 IMAGE 对象的句柄，TransparentBlt 函数需要用
	HDC dstDC = GetImageHDC(pDestImg);
	HDC srcDC = GetImageHDC(pSrcImg);

	int w = min(pSrcImg->getwidth(), destWidth);
	int h = min(pSrcImg->getheight(), destHeight);

	// 使用 Windows GDI 函数实现透明位图
	TransparentBlt(dstDC, destX, destY, w, h, srcDC, srcX, srcY, w, h, 0xff00ff);
}

// 获取鼠标位置
inline POINT GetCursorPos()
{
	HWND hwnd = GetHWnd();			// 获取绘图窗口句柄
	POINT point;
	GetCursorPos(&point);			// 获取鼠标指针位置（屏幕坐标）
	ScreenToClient(hwnd, &point);	// 将鼠标指针位置转换为窗口坐标

	return point;
}

// 判断键盘是否按下
// @param key：按键值，字母、数字，直接用IsKeyDown('Q')，IsKeyDown('A')等，
//				其他按键需要使用虚拟键码：IsKeyDown(VK_F1)，IsKeyDown(VK_ESCAPE)，百度虚拟键码可找到所有定义
inline bool IsKeyDown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000 ? 1 : 0);
}