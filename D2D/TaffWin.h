
#include <Windows.h>

#include <cstdlib>
#include <malloc.h>
#include <memory>
#include <string.h>
#include <tchar.h>
#include <math.h>

#include <d2d1.h>

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

template <class Interface>
inline void SafeRelease( Interface **ppInterfaceToRelease)
{
	if (**ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

#ifndef Assert
#if defined ( DEBUG ) || defined ( _DEBUG )
#define Assert(b) do {if ( !(b) )) { OutputDebugStringA("Assert: " #b "\n"); }} while( 0 );
#else
#define Assert(b)
#endif
#endif

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT (( HINSTANCE ) &__ImageBase )
#endif


//Direct2D resources class;
class Direct2DRes
{
public:
	HRESULT InitializeD2D();
	HRESULT BeginDrawRect();
	void	GetScreenDPI(FLOAT*, FLOAT*);
private:
	ID2D1Factory*		   pD2DFactory;
	ID2D1HwndRenderTarget* pRT;
	ID2D1SolidColorBrush*  pBlackBrush;
};

//Global vars
extern HINSTANCE hInst;
extern HWND hWnd;