#ifndef __MenuScene_H__
#define __MenuScene_H__

#include "cocos2d.h"
USING_NS_CC;

class MenuScene : public Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(MenuScene);
};
#endif