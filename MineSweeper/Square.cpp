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