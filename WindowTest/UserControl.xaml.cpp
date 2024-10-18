#include "pch.h"
#include "UserControl.xaml.h"
#if __has_include("UserControl.g.cpp")
#include "UserControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::WindowTest::implementation
{
    void UserControl::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        for( int i=0; i < 20; i++ )
        {
            windows_.emplace_back(BlankWindow());
            windows_[windows_.size() - 1].Activate();
        }
    }
}
