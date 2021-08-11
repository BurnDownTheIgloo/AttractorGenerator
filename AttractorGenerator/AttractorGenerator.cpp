// AttractorGenerator.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "framework.h"
#include "AttractorGenerator.h"
#include <vector>
#include <string>
#include "Region.h"
#include "Tetrahedron.h"
#include "DrawnLine.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

Region region;


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    // TODO: Place code here.

    POINT screen_center = { 700, 350 };
    region = Region(screen_center, 300, 500);

    //Floor

    for (int i = -5; i < 5; i++) {
        for (int j = -5; j < 5; j++) {
            region.AddShape(Cube(Point3D(i * 100 - 1200, 700, j * 100 + 2100), 100));
        }
    }

    //Endfloor



    //region.AddShape(Cube(Point3D(0, 0, 0), 50));
    region.AddShape(Cube(Point3D(150, 300, 50), 100));
    region.AddShape(Cube(Point3D(-235, -150, -300), 75));
    region.AddShape(Cube(Point3D(735, -600, 600), 125));

    region.AddShape(Tetrahedron(Point3D(0, 0, 0), 100));
    region.AddShape(Tetrahedron(Point3D(-150, -200, 150), 150));
    region.AddShape(Tetrahedron(Point3D(500, 300, 100), -200));


    // ENDTODO

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ATTRACTORGENERATOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed! (Type 1)"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ATTRACTORGENERATOR));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ATTRACTORGENERATOR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(CreateSolidBrush(RGB(0,0,0)));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ATTRACTORGENERATOR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
       MessageBox(NULL,
           _T("Call to RegisterClassEx failed! (Type 2)"),
           _T("Windows Desktop Guided Tour"),
           NULL);

      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            SetTextColor(hdc, RGB(255, 255, 255));
            SetBkMode(hdc, TRANSPARENT);

            TCHAR greeting[] = _T("Hello, Desktop");

            TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
            
            HPEN open = CreatePen(PS_SOLID, 1, RGB(255, 0, 255));
            HPEN pen = CreatePen(PS_SOLID, 2, RGB(150, 150, 255));
            SelectObject(hdc, pen);



            region.Draw(hdc);



            SelectObject(hdc, open);

            POINT oarray[4] = { region.GetOrigin().x - 300, region.GetOrigin().y, region.GetOrigin().x + 300, region.GetOrigin().y, region.GetOrigin().x, region.GetOrigin().y + 300, region.GetOrigin().x, region.GetOrigin().y - 300 };
            BYTE otypes[4] = { PT_MOVETO, PT_LINETO, PT_MOVETO, PT_LINETO };

            PolyDraw(hdc, oarray, otypes, 4);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}