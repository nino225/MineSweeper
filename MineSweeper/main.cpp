//
//  main.cpp
//  MineSweeper
//
//  Created by 二宮 章太 on 2014/12/27.
//  Copyright (c) 2014年 二宮 章太. All rights reserved.
//

#include <iostream>
#include "GameManager.h"

int main(int argc, const char * argv[]) {
    
    GameManager* gameManager = GameManager::getInstance();
    
    gameManager->GoGame();
    
    
    
    return 0;
}
