

#include <iostream>

int main()
{
    std::cout << "FuckLastActivityView\n";
    std::cout << "Deleting Prefetch folder..\n";

    system(R"(rmdir /S C:\Windows\Prefetch)");

    std::cout << "Creating Prefetch folder..\n";

    system(R"(mkdir C:\Windows\Prefetch)");

    std::cout << "Deleting registry keys..\n";
    system(R"(reg delete HKEY_CURRENT_USER\Software\Microsoft\Windows\Shell /f)");
    system(R"(reg delete "HKEY_CURRENT_USER\Software\Classes\Local Settings\Software\Microsoft\Windows\Shell" /f)");
    system(R"(reg delete HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\ComDlg32\OpenSavePidlMRU /f)");

    std::cout << "Deleting tokens from Event Viewer..\n";
    system(R"(@echo off && for /F "tokens=*" %1 in ('wevtutil.exe el') DO wevtutil.exe cl "%1")");
    std::cout << "Done!";

    system("pause");
}
