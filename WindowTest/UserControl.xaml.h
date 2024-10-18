#pragma once

#include "UserControl.g.h"

namespace winrt::WindowTest::implementation
{
    struct UserControl : UserControlT<UserControl>
    {
    private:

        std::vector<Microsoft::UI::Xaml::Window> windows_;

    public:

        UserControl()
            : windows_()
        {
        }

        ~UserControl()
        {
            ::OutputDebugStringW(L"Delete UserControl\n");
            for (auto w : windows_)
            {
                w.Close();
                w = nullptr;
            }
        }

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WindowTest::factory_implementation
{
    struct UserControl : UserControlT<UserControl, implementation::UserControl>
    {
    };
}
