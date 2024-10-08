// Compile With gcc window.c -o window.exe -lgdi32
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <tchar.h>

const TCHAR CLSNAME[] = TEXT("helloworldWClass");
LRESULT CALLBACK winproc(HWND hwnd, UINT wm, WPARAM wp, LPARAM lp);

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PSTR cmdline, int cmdshow)
{
    WNDCLASSEX wc;
    MSG msg;
    HWND hwnd;

    wc.cbSize = sizeof(wc);
    wc.style = 0;
    wc.lpfnWndProc = winproc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = CLSNAME;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, TEXT("Could not register window class"),
            NULL, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_LEFT,
        CLSNAME,
        NULL,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInst,
        NULL);
    if (!hwnd) {
        MessageBox(NULL, TEXT("Could not create window"), NULL, MB_ICONERROR);
        return 0;
    }

    HWND hwndONE = CreateWindow(
        L"BUTTON",  
        L"One", 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  
        420,         
        300,         
        100,        
        70,        
        hwnd,     
        (HMENU)1,      
        hInst,
        NULL);      

    HWND hwndTWO= CreateWindow(
        L"BUTTON",  
        L"Two",      
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        530,        
        300,        
        100,        
        70,       
        hwnd,     
        (HMENU)2,       
        hInst,
        NULL);      
    HWND hwndQUIT = CreateWindow(
        L"BUTTON",  
        L"Quit",      
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        475,         
        380,     
        100,        
        70,        
        hwnd,     
        (HMENU)3,       
        hInst,
        NULL);      

    HWND Label = CreateWindowEx(
        WS_EX_TRANSPARENT,
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU,
        490,
        240,
        90,
        50,
        hwnd,
        (HMENU)4,
        hInst, NULL);

     HFONT font = CreateFont(
        40,//height
        15,//width
        0,
        0,
        600,
        FALSE,
        FALSE,
        FALSE,
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH,
        L"Arial" );
    SendMessage(Label,WM_SETFONT, (WPARAM)font, TRUE);
    ShowWindow(hwnd, cmdshow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

HBRUSH brush1 = CreateSolidBrush(RGB(
    0,
    100,
    20));

HBRUSH brush2 = CreateSolidBrush(RGB(
    100,
    0,
    20));

int btnCLICK = 0;
int count = 0;
LRESULT CALLBACK winproc(HWND hwnd, UINT wm, WPARAM wp, LPARAM lp)
{
    
    if (wm == WM_DESTROY) {
        PostQuitMessage(0);
    } if (wm == WM_COMMAND) {

        HWND Label = GetDlgItem(
            hwnd,
            4);
        SetWindowText(
            hwnd,
            L"Happy Halloween :)");
        if (count == 2) {
            MessageBox(hwnd, L"OK thats enough clicking", L"BN_CLICKED", MB_ICONERROR);
        }
        else if (count == 3) {
            MessageBox(hwnd, L"im serious :/", L"BN_CLICKED", MB_ICONERROR);
        }
        else if (count == 4) {
            MessageBox(hwnd, L"fine idc", L"BN_CLICKED", MB_ICONERROR);
        }
        else if (count == 5) {
            MessageBox(hwnd, L"BOO!", L"BN_CLICKED", MB_ICONERROR);
        }
        else if (count == 6) {
            MessageBox(hwnd, L"See what happens when you mess around ;)", L"BN_CLICKED", MB_ICONERROR);
        }
        if (HIWORD(wp) == BN_CLICKED && LOWORD(wp) == 1) {
            
            SetWindowText(
                Label,
                L"ONE");

            btnCLICK = 1;
            count++;
            InvalidateRect(hwnd, NULL, TRUE);
            
        }
        else if (HIWORD(wp) == BN_CLICKED && LOWORD(wp) == 2) {
            SetWindowText(
                Label,
                L"TWO");

            btnCLICK = 2;
            count++;

            InvalidateRect(hwnd, NULL, TRUE);
            //if (brush2) DeleteObject(brush2);
        }
        
        else if (HIWORD(wp) == BN_CLICKED && LOWORD(wp) == 3) {
            PostQuitMessage(0);
        }

    }

    if (wm == WM_ERASEBKGND) {
        if (btnCLICK == 1) {
            HDC hdc = (HDC)wp;
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, brush1);


        }else if (btnCLICK == 2) {
            HDC hdc = (HDC)wp;
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, brush2);
        }
        return 1;

    }
    return DefWindowProc(hwnd, wm, wp, lp);
}