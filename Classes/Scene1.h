#ifndef __SCENE1_H__
#define __SCENE1_H__


#include "cocos2d.h"
USING_NS_CC;

class TankMove : public Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(TankMove);
};
#endif