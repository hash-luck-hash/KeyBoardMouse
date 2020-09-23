#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<fstream>
using namespace std;
double velocity=0;
double x,y;
int horizontal,vertical;
bool ControlB = false;

void updateCursor(){
    if (GetKeyState(VK_UP) & 0x8000){
        if(y>=0)
            y-=velocity;
        }
    if (GetKeyState(VK_DOWN) & 0x8000){
        if(y<=vertical)
           y+=velocity;
        }
    if (GetKeyState(VK_LEFT) & 0x8000){
           if(x>=0)
           x-=velocity;
        }
    if (GetKeyState(VK_RIGHT) & 0x8000){
           if(x<=horizontal)
           x+=velocity;
        }
        SetCursorPos(x,y);

       // cout<<velocity<<"\n";
        //cout<<x<<" "<<y<<endl;
}
bool IsDouble(const std::string& s)
{
  std::istringstream i(s);
  double temp;
  return ( (i >> temp) ? true : false );
}
void isRead(){
    fstream file;
    file.open("velocity.txt",ios::in | ios::out);
    if(file.good()==true){
        char var[255];
        file.getline(var,255);
        
        int v = 0;
        string lb="";
        while(true){
            if(v==strlen(var)) break;
           lb+=var[v];
            v++;
        }
        if(!IsDouble(lb)) return;
        velocity = stod(lb);
        cout<<velocity<<"\n";
        file.close();
    } else { return;}
}
void Press(){
    if((GetKeyState(VK_CONTROL) & 0x8000)&&(GetKeyState('B') & 0x8000)){
        if(ControlB == false)
         ControlB = true;
         else ControlB = false;
    }
}
bool isPressed(){
    if(ControlB) return true;
    else return false;
}
int main(){
        

    HWND wind = GetConsoleWindow();
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();

    GetWindowRect(hDesktop, &desktop);
     horizontal = desktop.right;
     vertical = desktop.bottom;
    ShowWindow(wind,SW_HIDE);
    
    time_t timer;
    srand(time(&timer));
    x=rand()%500,y=rand()%500;

    isRead();
    if(velocity==0) { return 0;}
    while(true){
        if(!isPressed())
        updateCursor();

        isRead();
        Press();
    }
    
    return 0;
}