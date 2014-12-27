//
//  GameManager.h
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#ifndef __MineSweeper__GameManager__
#define __MineSweeper__GameManager__

#include "Field.h"

class GameManager
{
public:
    const int NUM_ROWS = 5;
    const int NUM_COLS = 5;
    const int NUM_MINES = 5;
    
    const bool IS_DEBUG_MODE = false;
    
    enum TurnStatus
    {
        StartTurn,
        WaitInput,
        DoAction,
        ShowGrid,
        EndTurn,
        
        StartGame = 100,
    };
    
    static GameManager* getInstance ();
    
    void GoGame ();
    
private:
    enum InputType
    {
        None,
        Open,
        PutMineChecker
    };
    
    GameManager ();
    
    Field* field;
    
    bool isGameOver;
    
    int inputRow, inputCol;
    InputType inputType;
    
    TurnStatus nextTurnStatus;
    
    static GameManager* instance;
    
    void init ();
    
    void goNextStatus ();
    
    void onStartGame ();
    
    void onStartTurn ();
    void onWaitInput ();
    void onDoAction ();
    void onShowGrid ();
    void onEndTurn ();
    void gameOver ();
    void gameClear ();
    
    void open ();
    
};

#endif /* defined(__MineSweeper__GameManager__) */
