//
//  Square.cpp
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#include "Square.h"
#include <iostream>

Square::Square (int row, int col, Square::SquareType type)
: row(row), col(col), type(type)
{
    status = Invisible;
}

Square::SquareStatus Square::GetStatus()
{
    return status;
}

char Square::GetStatusCharacter()
{
    char ret;
    switch (status) {
        case Opened:
            //TODO: 周りの地雷の数を計算する機構をつくったらそれを表示
            ret = '0';
            if (type == Mine) ret = '1';
            break;
            
        case MineChecker:
            ret = 'x';
            break;
            
        case Invisible:
            ret = ' ';
            
        default:
            break;
    }
    
    return ret;
}

Square::SquareType Square::GetType()
{
    return type;
}

void Square::OnOpened()
{
    if (status == Opened)
    {
        std::cout << "ERROR : このマスはすでに開かれています。" << std::endl;
        return;
    }
    status = Opened;
}

void Square::OnCheckedMine()
{
    if (status == Opened)
    {
        std::cout << "ERROR : このマスはすでに開かれています。" << std::endl;
        return;
    }
    status = MineChecker;
}