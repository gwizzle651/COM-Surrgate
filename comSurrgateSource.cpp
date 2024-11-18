#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>

bool progRun = true;

int customQuit () {
     progRun = 0;
     return 0;
}

int runCheck (bool flag) {
    if (flag == false) {
        std::exit(0);
    }
    else {
        return 0;
    }
}

std::wstring getDesktopPath() {
    wchar_t path[MAX_PATH];

    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_DESKTOP, NULL, 0, path))) {
        return std::wstring(path);
    }
    
    return L"";
}

int main() {
    FreeConsole();
    std::wstring desktopPath = getDesktopPath();
    
    if (desktopPath.empty()) {
        return 1;
    }

    std::string filePath = std::string(desktopPath.begin(), desktopPath.end()) + "\\message.txt";
    std::string filePath2 = std::string(desktopPath.begin(), desktopPath.end()) + "\\uhh.txt";
    std::string filePath3 = std::string(desktopPath.begin(), desktopPath.end()) + "\\bye.txt";
    std::string filePath4 = std::string(desktopPath.begin(), desktopPath.end()) + "\\foundYou.txt";
    

    std::ofstream message(filePath);
    
    if (message.is_open()) {
        message << "Warning: You have been hacked!" << "\n" << "-13.831327962404306, -171.76865994632686" << std::endl;
        message.close();
    } else {
        return 1;
    }

   while (progRun == true) {
        Sleep(60000);
        std::ofstream message2(filePath2);

        if (message2.is_open()) {
            message2 << "\n" <<"Warning: You are still hacked..." << "\n" << "51.178844, -1.826323" << std::endl;
            message2.close();
        } 
        else {
            return 1;
        }
        Sleep(120000);
        std::ofstream message3(filePath3);
        if (message3.is_open()) {
            message3 << "\n" <<"Warning: Fine. You suck at this, so I will go away." << "\n" << "52.54735960603655, 62.50001084216494" << std::endl;
            message3.close();
        } 
        else {
            return 1;
        }
        Sleep(120000);
        std::ofstream message4(filePath4);
        if (message4.is_open()) {
            message4 << "\n" <<"Warning: He found you..." << std::endl;
            message4.close();
        } else {
            return 1;
        }
        Sleep(10000);
        customQuit();
        runCheck(progRun);
    }
    return 0;
}
