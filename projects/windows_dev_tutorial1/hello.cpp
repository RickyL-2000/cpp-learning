#include <windows.h>

int WINAPI WinMain (
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    // call API function MessageBox
    int nSelect = MessageBox(NULL, TEXT("Hello World!"), TEXT("Welcome"), MB_OKCANCEL);
    if (nSelect == IDOK) {
        MessageBox(NULL, TEXT("you clicked OK"), TEXT("NOTE"), MB_OK);
    } else {
        MessageBox(NULL, TEXT("you clicked cancel"), TEXT("NOTE"), MB_OK);
    }

    return 0;
}