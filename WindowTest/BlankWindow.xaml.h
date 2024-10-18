#pragma once

#include "BlankWindow.g.h"
#include <App.xaml.h>
using namespace winrt;
#include <microsoft.ui.xaml.window.h>
#include <winrt/Microsoft.UI.Windowing.h>

namespace winrt::WindowTest::implementation
{
    struct BlankWindow : BlankWindowT<BlankWindow>
    {
        BlankWindow()
        {
            int window_width = 500;
            int window_height = 500;
            this->AppWindow().SetPresenter(winrt::Microsoft::UI::Windowing::AppWindowPresenterKind::CompactOverlay);
            this->AppWindow().Resize({ window_width, window_height });
            this->AppWindow().IsShownInSwitchers(false);
        }

        ~BlankWindow()
        {
            ::OutputDebugStringW(L"Delete BlankWindow\n");
        }
    };
}

namespace winrt::WindowTest::factory_implementation
{
    struct BlankWindow : BlankWindowT<BlankWindow, implementation::BlankWindow>
    {
    };
}
