#include "Scene3.h"
#include "ui/CocosGUI.h"
#include <iostream>

Scene* TankMove3::createScene()
{
    auto scene = Scene::create();
    auto layer = TankMove3::create();
    scene->addChild(layer);
    return scene;
}

bool TankMove3::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    
    //--------------------------------Atras------------------------------
    auto screen = Director::getInstance()->getWinSize();
    auto back = Sprite::create("back.png");
    back->setPosition(Point(screen.width/2+600, screen.height/2+300));
    back->setScale(0.85);
    this->addChild(back, 2);
    
    auto listenerBack = EventListenerTouchOneByOne::create();
    listenerBack->setSwallowTouches(true);
    
    listenerBack->onTouchBegan = [](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode))
        {
            Director::getInstance()->popScene();
            return true;
        }
        return false;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerBack, back);
    
    
    //--------------------------------Fondo------------------------------
    auto sprite = Sprite::create("minion.jpg");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 1);


    
    
    
    
    auto sprite1 = Sprite::create("boton.png");
    sprite1->setPosition(origin+Point(200, 200));
    sprite1->setScale(1.0);
    addChild(sprite1, 10);
    
    auto sprite2 = Sprite::create("boton.png");
    sprite2->setPosition(origin+Point(200, 600));
    sprite2->setScale(1.0);
    addChild(sprite2, 20);
    
    auto sprite3 = Sprite::create("boton.png");
    sprite3->setPosition(origin+Point(600, 200));
    sprite3->setScale(1.0);
    addChild(sprite3, 1);
    
    auto sprite4 = Sprite::create("boton.png");
    sprite4->setPosition(origin+Point(600, 600));
    sprite4->setScale(1.0);
    addChild(sprite4, 40);
    
    auto sprite5 = Sprite::create("boton.png");
    sprite5->setPosition(origin+Point(1000, 200));
    sprite5->setScale(1.0);
    addChild(sprite5, 50);
    
    auto sprite6 = Sprite::create("boton.png");
    sprite6->setPosition(origin+Point(1000, 600));
    sprite6->setScale(1.0);
    addChild(sprite6, 3);
    
    
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);

    
    //----------------------------------------------------------------------------Tocar El Cuadrado--------------------------------------------------------------
    listener1->onTouchBegan = [](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);

        if (rect.containsPoint(locationInNode))
        {
            target->setOpacity(0);
            return true;
        }
        return false;
    };
    
    
    //------------------------------------------------------------------------Añadir eventos al Sprite---------------------------------------------------------------
    //Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite1);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite2);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite3);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite4);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite5);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite6);
    
    
    
    
    return true;
}