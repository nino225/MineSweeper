//
//  Field.cpp
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#include "Field.h"
#include <iostream>


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
            cout << (char)GetGrid (row, col)->GetStatusCharacter () << " ";
        }
        cout << endl;
    }
}


