//
//  GameManager.cpp
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#include "GameManager.h"
#include <iostream>
using namespace std;

GameManager* GameManager::getInstance()
{
    return instance;
}

GameManager::GameManager()
{
    nextTurnStatus = StartGame;
};

GameManager* GameManager::instance = new GameManager ();

void GameManager::init()
{
    field = new Field (NUM_ROWS, NUM_COLS, NUM_MINES);
}

void GameManager::GoGame ()
{
    while (!isGameOver) {
        goNextStatus();
    }
}

void GameManager::goNextStatus()
{
    switch (nextTurnStatus) {
        case StartGame:
            onStartGame();
            nextTurnStatus = StartTurn;
            break;
            
        case StartTurn:
            onStartTurn();
            nextTurnStatus = WaitInput;
            break;
            
        case WaitInput:
            onWaitInput();
            nextTurnStatus = DoAction;
            break;
            
        case DoAction:
            onDoAction();
            nextTurnStatus = ShowGrid;
            break;
            
        case ShowGrid:
            onShowGrid();
            nextTurnStatus = EndTurn;
            break;
            
        case EndTurn:
            onEndTurn();
            nextTurnStatus = StartTurn;
            break;
            
        default:
            cout << "ERROR : nextTurnStatus is invalid." << endl;
            break;
    }
    
}

void GameManager::onStartGame()
{
    cout << "ゲームを開始します。" << endl;
    init();
    
    if (IS_DEBUG_MODE)
    {
        cout << "デバッグモードです。　地雷の場所と各マス付近の地雷の数を表示します" << endl;
        field->ShowGridMine();
        cout << endl;
    }
}

void GameManager::onStartTurn()
{
    cout << endl << endl;
}

void GameManager::onWaitInput()
{
    int row = -1;
    int col = -1;
    
    while (true)
    {

        do
        {
            cout << "選択する列・行を入力してください : ";
            string input;
            cin >> input;
            
            if (input.size() == 2)
            {
                row = (int)input[1] - '0';
                col = (int)input[0] - (int)Field::ORIGIN_COL_LABEL;
            }
            else
            {
                cout << "フォーマットが間違っています。 <例 : a0[Enter]> " << endl;
                continue;
            }
            
            
        }while (
                !(
                  0 <= row && row < field->GetRows() &&
                  0 <= col && col < field->GetCols()
                 )
                );
        
        // 指定されたマスが開かれているかどうかをチェック
        if (field->GetGrid(row, col)->GetStatus() != Square::SquareStatus::Opened)
        {
            break;
        }
        else
        {
            cout << "指定されたマスはすでに開かれています。できることはありません。" << endl;
        }
    
    };
    
    inputCol = col;
    inputRow = row;
    
    
    
    InputType type = None;

    do{
        cout << "開く場合はoを、地雷チェックの場合はxを入力してください : ";
        
        string input;
        cin >> input;
        
        if (input.size() > 0)
        {
            switch (input[0]) {
                case 'o':
                    type = Open;
                    break;
                    
                case 'x':
                    type = PutMineChecker;
                    break;
                    
                default:
                    break;
            }
        }
        
    } while (type == None);
    
    inputType = type;
    cout << endl;
    
}

void GameManager::onDoAction()
{
    switch (inputType)
    {
        case Open:
            open();
            break;
            
        case PutMineChecker:
            field->GetGrid(inputRow, inputCol)->OnCheckedMine();
            break;
            
        default:
            break;
    }
}

void GameManager::onShowGrid()
{
    field->ShowGrid();
}

void GameManager::onEndTurn ()
{
    nextTurnStatus = StartTurn;
}

void GameManager::open()
{
    Square* square = field->GetGrid(inputRow, inputCol);
    if (square->GetType() != Square::SquareType::Mine)
    {
        square->OnOpened();
    }
    else
    {
        gameOver();
    }
}

void GameManager::gameOver()
{
    cout << " ゲームオーバー" << endl;
    isGameOver = true;
}
