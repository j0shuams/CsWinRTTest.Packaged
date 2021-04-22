#include "pch.h"

using namespace winrt;
using namespace Coords;
using namespace Windows::Foundation;

int __stdcall wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    init_apartment(apartment_type::single_threaded);
    std::wostringstream wostringstream;

    Coord a(0.0, 0.0);
    auto aStr = a.ToString();
    double bx = 39.0;
    double by = 80.0;
    Coord b(bx, by);
    auto bStr = b.ToString();
    auto aToB = a.Distance(b);

    wostringstream << L"We expect the distance between " << aStr.c_str() << L" and " << bStr.c_str() << L" to be 89.0" << std::endl;

    std::wostringstream anotherStream;
    anotherStream << L"Calculated distance was " << a.Distance(b) << std::endl;

    ::MessageBoxW(::GetDesktopWindow(), wostringstream.str().c_str(), L"C++/WinRT Desktop Application", MB_OK);
    ::MessageBoxW(::GetDesktopWindow(), anotherStream.str().c_str(), L"Another pop up", MB_OK);
}
