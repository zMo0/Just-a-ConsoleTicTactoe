//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) {
    int row = game_state.get_selectedRow();
    int col = game_state.get_selectedColumn();
    
    if (game_state.get_gameBoard(row, col)!= Empty){
        game_state.set_moveValid(false);
        return;
    }
    else{
        game_state.set_winCode(0);
        game_state.set_gameOver(false);
        game_state.set_moveValid(true);
        game_state.set_gameBoard(row, col, game_state.get_turn());
        
        bool turn = game_state.get_turn();
        game_state.set_turn(!turn);
        
        int gameboard[3][3];
        for (int i = 0; i < 3; i++){
            for (int a = 0; a < 3; a++){
                gameboard[i][a] = game_state.get_gameBoard(i,a);
            }
        }
        
        if(gameboard[0][0] == 1 && gameboard[0][1] == 1 && gameboard[0][2] == 1
           ||gameboard[0][0] == -1 && gameboard[0][1] == -1 && gameboard[0][2] == -1){
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
        }
        if(gameboard[1][0] == 1 && gameboard[1][1] == 1 && gameboard[1][2] == 1 
           ||gameboard[1][0] == -1 && gameboard[1][1] == -1 && gameboard[1][2] == -1 ){
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
        }
        if(gameboard[2][0] == 1 && gameboard[2][1] == 1 && gameboard[2][2] == 1
           ||gameboard[2][0] == -1 && gameboard[2][1] == -1 && gameboard[2][2] == -1 ){
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
        }
        if(gameboard[0][0] == 1 && gameboard[1][0] == 1 && gameboard[2][0] == 1
          ||gameboard[0][0] == -1 && gameboard[1][0] == -1 && gameboard[2][0] == -1 ){
            game_state.set_winCode(4);
            game_state.set_gameOver(true);
        }
        if(gameboard[0][1] == 1 && gameboard[1][1] == 1 && gameboard[2][1] == 1
                ||gameboard[0][1] == -1 && gameboard[1][1] == -1 && gameboard[2][1] == -1 ){
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
        }
        if(gameboard[0][2] == 1 && gameboard[1][2] == 1 && gameboard[2][2] == 1
                ||gameboard[0][2] == -1 && gameboard[1][2] == -1 && gameboard[2][2] == -1 ){
            game_state.set_winCode(6);
            game_state.set_gameOver(true);
        }
        if(gameboard[0][0] == 1 && gameboard[1][1] == 1 && gameboard[2][2] == 1
                ||gameboard[0][0] == -1 && gameboard[1][1] == -1 && gameboard[2][2] == -1 ){
            game_state.set_winCode(7);
            game_state.set_gameOver(true);
        }
        if(gameboard[0][2] == 1 && gameboard[1][1] == 1 && gameboard[2][0] == 1
                ||gameboard[0][2] == -1 && gameboard[1][1] == -1 && gameboard[2][0] == -1 ){
            game_state.set_winCode(8);
            game_state.set_gameOver(true);
        }
        return;
    }
    
}

