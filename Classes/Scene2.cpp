#include "Scene2.h"
#include "ui/CocosGUI.h"
#include <iostream>

Scene* TankMove2::createScene()
{
    auto scene = Scene::create();
    auto layer = TankMove2::create();
    scene->addChild(layer);
    return scene;
}

bool TankMove2::init()
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
    
    
    //Create a "one by one" touch event listener (processes one touch at a time)
    auto listener1 = EventListenerTouchOneByOne::create();
    // When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
    listener1->setSwallowTouches(true);
    
    //-------------------------------------------------------------------------Tocar El Cuadrado--------------------------------------------------------------
    // Example of using a lambda expression to implement onTouchBegan event callback function
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        // event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        std::cout << "1-Tocar Cuadrado" << std::endl;
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            //log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setOpacity(180);
            return true;
        }
        return false;
    };
    
    
    //-----------------------------------------------------------------------Mover el cuadrado-----------------------------------------------------------------
    //Trigger when moving touch
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        //Move the position of current button sprite
        target->setPosition(target->getPosition() + touch->getDelta());
        std::cout << "2-Moviendo Cuadrado" << std::endl;
    };
    
    
    //----------------------------------------------------------------------Soltar Cuadrado-------------------------------------------------------------------------
    //Process the touch end event
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        //log("sprite onTouchesEnded.. ");
        target->setOpacity(255);
        //Reset zOrder and the display sequence will change
        if (target == sprite2)
        {
            sprite1->setZOrder(100);
        }
        else if(target == sprite1)
        {
            sprite1->setZOrder(0);
        }
        std::cout << "3-Soltar Cuadrado" << std::endl;
    };
    
    
    //------------------------------------------------------------------------Añadir eventos al Sprite---------------------------------------------------------------
    //Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite1);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite2);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite3);
    
    
    

    
    
    
    
    return true;
}