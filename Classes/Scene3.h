//
//  Scene3.h
//  CambiarScenes
//
//  Created by Asier Cortes on 26/3/15.
//
//

#ifndef __CambiarScenes__Scene3__
#define __CambiarScenes__Scene3__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class TankMove3 : public Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(TankMove3);
};
#endif