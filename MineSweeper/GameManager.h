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
    
    void GameReset ();
    
private:
    
    const int MAX_ROWS = 26;
    const int MAX_COLS = 26;
    const int MAX_MINES = 26 * 26;
    
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
