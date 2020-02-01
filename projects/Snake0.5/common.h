#pragma once
#include <graphics.h>
#include <Windows.h>
// ���øÿ����ʹ�� TransparentBlt ����
#pragma comment( lib, "MSIMG32.LIB")


// ֧��͸�����Ƶ�putimage��
// pDestImgΪ�ձ�ʾ��pSrcImg������Ļ�ϣ����򻭵�pDestImg��
// ͸��ɫΪ��ɫ�������زı���������ַ�ɫ��Ҫ����������͸���ĵط�Ҳ͸����
// ��Դ��Ҫʹ��bmp��ʽ����Ϊjpg���Ż����أ�����ĳЩ͸�����ص㲻�����ۡ�
inline void putimagex(int destX, int destY, int destWidth, int destHeight, IMAGE *pSrcImg, int srcX, int srcY, IMAGE *pDestImg = NULL)
{
	if (pSrcImg == NULL)
	{
		return;
	}
	// ��ȡ��ͼ���ں� IMAGE ����ľ����TransparentBlt ������Ҫ��
	HDC dstDC = GetImageHDC(pDestImg);
	HDC srcDC = GetImageHDC(pSrcImg);

	int w = min(pSrcImg->getwidth(), destWidth);
	int h = min(pSrcImg->getheight(), destHeight);

	// ʹ�� Windows GDI ����ʵ��͸��λͼ
	TransparentBlt(dstDC, destX, destY, w, h, srcDC, srcX, srcY, w, h, 0xff00ff);
}

// ��ȡ���λ��
inline POINT GetCursorPos()
{
	HWND hwnd = GetHWnd();			// ��ȡ��ͼ���ھ��
	POINT point;
	GetCursorPos(&point);			// ��ȡ���ָ��λ�ã���Ļ���꣩
	ScreenToClient(hwnd, &point);	// �����ָ��λ��ת��Ϊ��������

	return point;
}

// �жϼ����Ƿ���
// @param key������ֵ����ĸ�����֣�ֱ����IsKeyDown('Q')��IsKeyDown('A')�ȣ�
//				����������Ҫʹ��������룺IsKeyDown(VK_F1)��IsKeyDown(VK_ESCAPE)���ٶ����������ҵ����ж���
inline bool IsKeyDown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000 ? 1 : 0);
}