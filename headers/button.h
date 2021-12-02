#pragma once
struct button{
    const char * value;
    int x;
    int y;
    int width = 300;
    int height = 300;
    button(const char * Value,int X,int Y);
    void draw();
    bool isClicked();
};