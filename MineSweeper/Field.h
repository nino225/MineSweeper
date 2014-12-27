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
    const char ORIGIN_COL_LABEL = 'a';
    
    Field (int rows, int cols, int mines);
    
    Square* GetGrid (int row, int col) const;
    
    void ShowGrid () const;
    
private:
    int rows;
    int cols;
    int mines;
    
    std::vector< std::vector<Square*>> grid;
    
    void initGrid ();
    
};

#endif /* defined(__MineSweeper__Field__) */
