/*
 *  https://github.com/Exerros
 *  11.24.2020
*/

#include "epg_window.hpp"

#ifdef Windows
#include <windows.h>

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}
#endif

int main()
{
#ifdef Windows
    HideConsole();
#endif
//Here, the program window object is created. It sets all the necessary
//settings and transfers the loop control from the FLTK library.
    epg::EPG_Window window;

    return Fl::run();
}
