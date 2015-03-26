#include "MenuScene.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "ui/CocosGUI.h"
#include <iostream>

//calculate linear intrpolation
Point lerp(Point p1, Point p2, float percentage)
{
    return (p1 * (1 - (percentage / 100.f))) + (p2 * (percentage / 100.f));
}

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    auto screen = Director::getInstance()->getWinSize();
    
    auto menu_label = LabelTTF::create("Pulsa en una escena para ir a ella","Arial",32);
    menu_label->setPosition(screen.width/2, screen.height/2+300);
    this->addChild(menu_label);
    
    auto scene1_label = LabelTTF::create("Tocar Cuadrados", "Arial", 24);
    auto scene2_label = LabelTTF::create("Mover Cuadrados", "Arial", 24);
    auto scene3_label = LabelTTF::create("Juego Foto", "Arial", 24);
    
    auto scene1_menu = MenuItemLabel::create(scene1_label, [](Ref* sender)
    {
        Director::getInstance()->pushScene(TankMove::createScene());
        std::cout << "Escena Clickada: 1" << std::endl;
    });
    
    auto scene2_menu = MenuItemLabel::create(scene2_label, [](Ref* sender)
    {
        Director::getInstance()->pushScene(TankMove2::createScene());
        std::cout << "Escena Clickada: 2" << std::endl;
    });
    
    auto scene3_menu = MenuItemLabel::create(scene3_label, [](Ref* sender)
    {
        Director::getInstance()->pushScene(TankMove3::createScene());
        std::cout << "Escena Clickada: 3" << std::endl;
    });
    
    auto menu = Menu::create(scene1_menu,scene2_menu,scene3_menu,nullptr);
    menu->setPosition(Point(screen.width/2,screen.height/2));
    this->addChild(menu, 1);
    scene1_menu->setPosition(lerp(Point(0, menu->getPositionY() - menu->getContentSize().height / 2), Point(0, menu->getPositionY() + menu->getContentSize().height / 2), 20));
    scene2_menu->setPosition(lerp(Point(0, menu->getPositionY() - menu->getContentSize().height / 2), Point(0, menu->getPositionY() + menu->getContentSize().height / 2), 10));
    scene3_menu->setPosition(lerp(Point(0, menu->getPositionY() - menu->getContentSize().height / 2), Point(0, menu->getPositionY() + menu->getContentSize().height / 2), 30));
    
    return true;
}