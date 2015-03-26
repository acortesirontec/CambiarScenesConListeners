#ifndef __SCENE2_H__
#define __SCENE2_H__

#include "cocos2d.h"
USING_NS_CC;

class TankMove2 : public Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(TankMove2);
};
#endif