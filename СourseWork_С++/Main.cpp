#include "Main_Menu.h"
#include <Windows.h>

using namespace —ourseWork—;


[STAThread]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Main_Menu);
    return 0;
}