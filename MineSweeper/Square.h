//
//  Square.h
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#ifndef __MineSweeper__Square__
#define __MineSweeper__Square__

class Square {
public:
    enum SquareType
    {
        None,
        Number,
        Mine
    };
    
    enum SquareStatus
    {
        Opened,
        Invisible,
        MineChecker
    };
    
    Square (int row, int col, SquareType type);
    
    SquareStatus GetStatus ();
    
    char GetStatusCharacter ();
    
    SquareType GetType ();
    
    char GetTypeCharacter ();
    
    void OnOpened ();
    
    void OnCheckedMine ();
    
private:
    SquareType type;
    
    SquareStatus status;
    
    int row;
    
    int col;
    
};

#endif /* defined(__MineSweeper__Square__) */
