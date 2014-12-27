//
//  main.cpp
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#include <iostream>
#include "Field.h"

int main(int argc, const char * argv[]) {

    Field field(5, 5, 5);
    
    field.ShowGrid();
    
    return 0;
}
