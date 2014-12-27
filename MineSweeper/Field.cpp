//
//  Field.cpp
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#include "Field.h"
#include <iostream>
#include <math.h>


using namespace std;

Field::Field (int rows, int cols, int mines)
:rows(rows), cols(cols), mines(mines)
{
    initGrid();
}

Square* Field::GetGrid (int row, int col) const
{
    return grid[row][col];
}

int Field::GetRows() const
{
    return rows;
}

int Field::GetCols() const
{
    return cols;
}


bool isContained (int row, int col, vector<pair<int, int>>& minePositions)
{
 
    for (int i = 0; i < minePositions.size (); i++) {
        if ( minePositions[i].first == row && minePositions[i].second == col)
            return true;
    }
    
    return false;
}

void Field::initGrid()
{
    grid.clear();
    
    srand((unsigned)time(NULL));
    
    //地雷の場所を決定
    vector< pair<int, int>> minePositions;
    for (int i = 0; i < mines; i++) {
        pair<int, int> pos;

        do
        {
            pos.first = rand() % rows;
            pos.second = rand() % cols;
        }while (isContained(pos.first, pos.second, minePositions));
        
        minePositions.push_back(pos);
    }
    
    
    
    // grid の生成
    for (int row = 0; row < rows; row++) {
        
        vector<Square*> line;
        for (int col = 0; col < cols; col++) {
            Square::SquareType type;
            
            if (isContained(row, col, minePositions))
                type = Square::SquareType::Mine;
            else
                type = Square::SquareType::None;
            
            line.push_back(new Square::Square(row, col, type));
        }
        grid.push_back(line);
    }
}

void Field::ShowGrid() const
{
    //show col label
    cout << "  ";
    for (int i = 0; i < cols; i++) {
        cout << (char)(i + ORIGIN_COL_LABEL) << " ";
    }
    cout << endl;
    
    for (int row = 0; row < rows; row++) {
        // show row label
        std::cout << row << " ";
        for (int col = 0; col < cols; col++)
        {
            cout << (char)getStatusCharacter (row, col) << " ";
        }
        cout << endl;
    }
}

int Field::nearSquareMines(int row, int col) const
{
    int sum = 0;
    
    for (int i = max(row - 1, 0); i <= min(row + 1, rows - 1); i++)
    {
        for (int j = max(col - 1, 0); j <= min(col + 1, cols - 1); j++)
        {
            if (i == row && j == col) continue;
            
            if (GetGrid(i, j)->GetType() == Square::SquareType::Mine)
            {
                sum++;
            }
        }
    }
    
    return sum;
}

void Field::ShowGridMine () const
{
    //show col label
    cout << "  ";
    for (int i = 0; i < cols; i++) {
        cout << (char)(i + ORIGIN_COL_LABEL) << " ";
    }
    cout << endl;
    
    for (int row = 0; row < rows; row++) {
        // show row label
        std::cout << row << " ";
        for (int col = 0; col < cols; col++)
        {
            char squareType;
            if (GetGrid(row, col)->GetType() == Square::SquareType::Mine)
                squareType = 'x';
            else
                squareType = '0' + nearSquareMines(row, col);
            
            cout << (char)squareType << " ";
        }
        cout << endl;
    }
}

char Field::getStatusCharacter(int row, int col) const
{
    char ret;
    switch (GetGrid(row, col)->GetStatus()) {
        case Square::SquareStatus::Opened:
            //TODO: 周りの地雷の数を計算する機構をつくったらそれを表示
            ret = '0' + nearSquareMines(row, col);
            break;
            
        case Square::SquareStatus::MineChecker:
            ret = 'x';
            break;
            
        case Square::SquareStatus::Invisible:
            ret = '?';
            
        default:
            break;
    }
    
    return ret;
}
