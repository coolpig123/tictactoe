#include "raylib.h"
#include "../headers/button.h"
button::button(const char * Value,int X,int Y){
    value = Value;
    x = X;
    y = Y;
}
    void button::draw(){
        DrawRectangle(x,y,width,height,DARKGRAY);
        DrawText(value,x+100,y+50,200,WHITE);
    }
    bool button::isClicked(){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= x && GetMouseX() <= x+width && GetMouseY() >= y && GetMouseY() <= y+height){
            return true;
        }
        return false;
    }

