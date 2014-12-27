//
//  Field.h
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#ifndef __MineSweeper__Field__
#define __MineSweeper__Field__

#include "Square.h"
#include <vector>

class Field
{
public:
    const static char ORIGIN_COL_LABEL = 'a';
    
    Field (int rows, int cols, int mines);
    
    Square* GetGrid (int row, int col) const;
    
    /*
     @brief
        現在のグリッドの状態を表示
     */
    void ShowGrid () const;
    
    /*
     @brief
        解答を表示
     @descriptor
        地雷の場所に'x'
        それ以外の場所は付近の地雷の数を表示
     */
    void ShowGridMine () const;
    
    int GetRows () const;
    
    int GetCols () const;
    
    bool IsGameClear () const;
    
    void Open(int row, int col);
    
private:
    int rows;
    int cols;
    int mines;
    
    std::vector< std::vector<Square*>> grid;
    
    void initGrid ();
    
    int nearSquareMines (int row, int col) const;
    
    char getStatusCharacter(int row, int col) const;
};

#endif /* defined(__MineSweeper__Field__) */
