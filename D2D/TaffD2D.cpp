#include "TaffWin.h"

RECT rc;

HRESULT Direct2DRes::InitializeD2D()
{

	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&pD2DFactory
		);

	GetClientRect(hWnd, &rc);

	if (SUCCEEDED(hr))
	{
		hr = pD2DFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(
			hWnd,
			D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top)
			),
			&pRT
			);
	}

	if (SUCCEEDED(hr))
	{
		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Black),
			&pBlackBrush
			);
	}

	return hr;
}

HRESULT Direct2DRes::BeginDrawRect()
{
	pRT->BeginDraw();

	pRT->SetTransform(D2D1::Matrix3x2F::Identity());

	pRT->Clear(D2D1::ColorF(D2D1::ColorF::Black));

	D2D1_SIZE_F rtSize = pRT->GetSize();

	int width = static_cast<int>(rtSize.width);
	int height = static_cast<int>(rtSize.height);

	for (int x = 0; x < width; x += 10)
	{
		pRT->DrawLine(
			D2D1::Point2F(static_cast<FLOAT>(x), 0.0f),
			D2D1::Point2F(static_cast<FLOAT>(x), rtSize.height),
			pBlackBrush,
			0.5f
			);
	}

	for (int y = 0; y < height; y += 10)
	{
		pRT->DrawLine(
			D2D1::Point2F(0.0f, static_cast<FLOAT>(y)),
			D2D1::Point2F(rtSize.width, static_cast<FLOAT>(y)),
			pBlackBrush,
			0.5f
			);
	}

	HRESULT hr = pRT->EndDraw();

	return hr;
	
}

void Direct2DRes::GetScreenDPI(FLOAT *dpi_x, FLOAT *dpi_y)
{
	pD2DFactory->GetDesktopDpi(dpi_x, dpi_y);
}