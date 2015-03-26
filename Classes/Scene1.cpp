#include "Scene1.h"
#include "ui/CocosGUI.h"
#include <iostream>

Scene* TankMove::createScene()
{
    auto scene = Scene::create();
    auto layer = TankMove::create();
    scene->addChild(layer);
    return scene;
}

bool TankMove::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto screen = Director::getInstance()->getWinSize();
    auto back_label = LabelTTF::create("Volver Atras", "Arial", 48);
    auto back_menu = MenuItemLabel::create(back_label, [](Ref* sender){ Director::getInstance()->popScene(); });
    auto menu = Menu::create(back_menu,nullptr);
    menu->setPosition(Point(screen.width/2, screen.height/2+300));
    this->addChild(menu);
    
    
    
    auto sprite1 = Sprite::create("boton.png");
    sprite1->setPosition(origin+Point(200, 300)); // + Point(-80, 80)
    sprite1->setScale(0.2);
    addChild(sprite1, 10);
    
    auto sprite2 = Sprite::create("boton.png");
    sprite2->setPosition(origin+Point(500, 200));
    sprite2->setScale(0.2);
    addChild(sprite2, 20);
    
    auto sprite3 = Sprite::create("boton.png");
    sprite3->setPosition(origin+Point(800, 300));
    sprite3->setScale(0.2);
    addChild(sprite3, 1);
    //sprite2->addChild(sprite3, 1);
    
    
    auto listener1 = EventListenerTouchOneByOne::create();
    auto listener2 = EventListenerTouchOneByOne::create();
    auto listener3 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    listener2->setSwallowTouches(true);
    listener3->setSwallowTouches(true);
    
    //----------------------------------------------------------------------------Tocar El Cuadrado--------------------------------------------------------------
    listener1->onTouchBegan = [](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            target->setOpacity(180);
            
            std::cout << "Cuadrado 1 tocado" << std::endl;
            return true;
        }
        
        return false;
    };
    
    listener2->onTouchBegan = [](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            target->setOpacity(180);
            
            std::cout << "Cuadrado 2 tocado" << std::endl;
            return true;
        }
        
        return false;
    };

    listener3->onTouchBegan = [](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            target->setOpacity(180);
            
            std::cout << "Cuadrado 3 tocado" << std::endl;
            return true;
        }
        
        return false;
    };

    
    //---------------------------------------------------------------------------Soltar Cuadrado-------------------------------------------------------------------------
    
    listener1->onTouchEnded = [=](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setOpacity(255);
    };

    listener2->onTouchEnded = [=](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setOpacity(255);
    };

    listener3->onTouchEnded = [=](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setOpacity(255);
    };
    
    
    
    //------------------------------------------------------------------------Añadir eventos al Sprite---------------------------------------------------------------
    //Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite1);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, sprite2);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, sprite3);
    
    

    
    
    
    
    
    
    return true;
}