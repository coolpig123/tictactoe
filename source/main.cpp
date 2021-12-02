#include <iostream>
#include "../headers/button.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>
using namespace std;

bool checkWin(button list[3][3],const char * player){
    for(int i = 0;i<3;i++){
        if(strcmp(list[i][0].value,list[i][1].value) == 0 && strcmp(list[i][1].value,list[i][2].value) == 0 && strcmp(list[i][2].value,player) == 0){
            return true;
        }else if(strcmp(list[0][i].value,list[1][i].value) == 0 && strcmp(list[1][i].value,list[2][i].value) == 0 && strcmp(list[2][i].value,player) == 0){
            return true;
        }
    }
    if(strcmp(list[0][0].value,list[1][1].value) == 0 && strcmp(list[1][1].value,list[2][2].value) == 0 && strcmp(list[2][2].value,player) == 0){
        return true;
    }else if(strcmp(list[0][2].value,list[1][1].value) == 0 && strcmp(list[1][1].value,list[2][0].value) == 0 && strcmp(list[2][0].value,player) == 0){
        return true;
    }
    return false;
}
bool tie(button list[3][3]){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(strcmp(list[i][j].value,"-") == 0){
                return false;
            }
        }
    }
    return true;
}
int main(){
    const int screenWidth = 900;
    const int screenHeight = 900;
    const char * player = "x";
    bool win = false;
    button one("-",0,0);
    button two("-",300,0);
    button three("-",600,0);
    button four("-",0,300);
    button five("-",300,300);
    button six("-",600,300);
    button seven("-",0,600);
    button eight("-",300,600);
    button nine("-",600,600);
    button buttons[3][3] = {{one,two,three},{four,five,six},{seven,eight,nine}};
    InitWindow(screenWidth,screenHeight,"tic tac toe");
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            if(!win){
                for(int i = 0;i<3;i++){
                    for(int j = 0;j<3;j++){
                        buttons[i][j].draw();
                    }
                }
            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    if(buttons[i][j].isClicked() && strcmp(buttons[i][j].value,"-") == 0){
                        buttons[i][j].value = player;
                        if(strcmp(player,"x") == 0){
                            player = "o";
                        }else if(strcmp(player,"o") == 0){
                            player = "x";
                        }
                    }
                }
            }
            }
            if(checkWin(buttons,"x")){

                ClearBackground(BLACK);
                DrawText("x won!",screenWidth-600,screenHeight/2-100,100,WHITE);
                DrawText("press space to restart",screenWidth-750,screenHeight/2,50,WHITE);
                win = true;
            }
            else if(checkWin(buttons,"o")){

                ClearBackground(BLACK);
                DrawText("o won!",screenWidth-600,screenHeight/2-100,100,WHITE);
                DrawText("press space to restart",screenWidth-750,screenHeight/2,50,WHITE);
                win = true;
            }else if(tie(buttons)){

                ClearBackground(BLACK);
                DrawText("tie",screenWidth-500,screenHeight/2-100,100,WHITE);
                DrawText("press space to restart",screenWidth-750,screenHeight/2,50,WHITE);
                win = true;
            }
            if(win && IsKeyPressed(KEY_SPACE)){
                win = false;
                for(int i = 0;i<3;i++){
                    for(int j = 0;j<3;j++){
                        buttons[i][j].value = "-";
                    }
                }
            }
            


        
            
        EndDrawing();
    }
    CloseWindow();  
}