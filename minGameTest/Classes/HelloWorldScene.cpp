#include "HelloWorldScene.h"
#include "common/StaticConstant.h"

USING_NS_CC;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !BaseScene::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    MenuItemImage *closeItem = MenuItemImage::create(
                                        STC::IMAGE_CLOSENORMAL.c_str(),
                                        STC::IMAGE_CLOSESELECT.c_str(),
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    Menu* menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    LabelTTF* label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    baseNode->addChild(label, 1);

    // add "HelloWorld" splash screen"
    Sprite* sprite = Sprite::create(STC::IMAGE_HELLOWORLD.c_str());

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    baseNode->addChild(sprite, 0);
        
    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
        
    Director* director = Director::getInstance();
    //创建Scene
    Scene* scene = MainScene::scene();
    //把scene包装一下
    Scene*dscene=TransitionFadeTR::create(1.2f, scene);//向右上波浪
    
    director->replaceScene(dscene);
    
    return;
    
    
    
//    dscene=TransitionJumpZoom::create(1.2f, scene);//跳跃式，原场景先会缩小，然后跳跃进来
    
//    dscene=TransitionFade::create(1.2f, scene);//淡出淡入，原场景淡出，新场景淡入  
//    dscene=TransitionFade::create(1.2f, scene,Color3B::WHITE);//第三个参数就是淡出淡入的颜色
//    
//    dscene=TransitionFlipX::create(1.2f, scene,TransitionScene::Orientation::LEFT_OVER);//x轴左翻
//    dscene=TransitionFlipX::create(1.2f, scene,TransitionScene::Orientation::RIGHT_OVER);//x轴右翻
//    dscene=TransitionFlipY::create(1.2f, scene,TransitionScene::Orientation::UP_OVER);//y轴上翻
//    dscene=TransitionFlipY::create(1.2f, scene,TransitionScene::Orientation::DOWN_OVER);//y轴下翻
//    
//    dscene=TransitionFlipAngular::create(1.2f, scene,TransitionScene::Orientation::LEFT_OVER);//有角度转的左翻
//    dscene=TransitionFlipAngular::create(1.2f, scene,TransitionScene::Orientation::RIGHT_OVER);//有角度转的右翻
//    dscene=TransitionFlipAngular::create(1.2f, scene,TransitionScene::Orientation::UP_OVER);//有角度转的上翻
//    dscene=TransitionFlipAngular::create(1.2f, scene,TransitionScene::Orientation::DOWN_OVER);//有角度转的下翻   
//    
//    dscene=TransitionZoomFlipX::create(1.2f, scene,TransitionScene::Orientation::LEFT_OVER);//带缩放效果x轴左翻
//    dscene=TransitionZoomFlipX::create(1.2f, scene,TransitionScene::Orientation::RIGHT_OVER);//带缩放效果x轴右翻
//    dscene=TransitionZoomFlipY::create(1.2f, scene,TransitionScene::Orientation::UP_OVER);//带缩放效果y轴上翻
//    dscene=TransitionZoomFlipY::create(1.2f, scene,TransitionScene::Orientation::DOWN_OVER);//带缩放效果y轴下翻
//    
//    dscene=TransitionZoomFlipAngular::create(1.2f, scene,TransitionScene::Orientation::LEFT_OVER);//带缩放效果且有角度转的左翻
//    dscene=TransitionZoomFlipAngular::create(1.2f, scene,TransitionScene::Orientation::RIGHT_OVER);//带缩放效果且有角度转的左翻
//    dscene=TransitionZoomFlipAngular::create(1.2f, scene,TransitionScene::Orientation::UP_OVER);//带缩放效果且有角度转的上翻
//    dscene=TransitionZoomFlipAngular::create(1.2f, scene,TransitionScene::Orientation::DOWN_OVER);//带缩放效果且有角度转的下翻
//    
//    dscene=TransitionShrinkGrow::create(1.2f, scene);//交错替换
//    dscene=TransitionRotoZoom::create(1.2f, scene);//旋转角度替换
//    
//    dscene=TransitionMoveInL::create(1.2f, scene);//新场景从左移入覆盖
//    dscene=TransitionMoveInR::create(1.2f, scene);//新场景从右移入覆盖
//    dscene=TransitionMoveInT::create(1.2f, scene);//新场景从上移入覆盖
//    dscene=TransitionMoveInB::create(1.2f, scene);//新场景从下移入覆盖
//    
//    dscene=TransitionSlideInL::create(1.2f, scene);//场景从左移入推出原场景
//    dscene=TransitionSlideInR::create(1.2f, scene);//场景从右移入推出原场景
//    dscene=TransitionSlideInT::create(1.2f, scene);//场景从上移入推出原场景
//    dscene=TransitionSlideInB::create(1.2f, scene);//场景从下移入推出原场景
//    
//    //以下三个需要检测opengl版本是否支持
//    //CCConfiguration::sharedConfiguration()->getGlesVersion() <= GLES_VER_1_0如果为真则为不支持
//    if(Configuration::getInstance()->supportsETC()){
//        dscene=TransitionCrossFade::create(1.2f, scene);//淡出淡入交叉，同时进行
////        dscene=TransitionRadialCCW::create(1.2f, scene);//顺时针切入
////        dscene=TransitionRadialCW::create(1.2f, scene);//逆时针切入        
//    }else{
//        dscene=TransitionFade::create(1.2f, scene);//淡出淡入，原场景淡出，新场景淡入  
//    }
//    
//    //以下两个需要先设置摄像机
//    director->setDepthTest(true);
//    dscene=TransitionPageTurn::create(1.2f, scene,false);//翻页，前翻
//    dscene=TransitionPageTurn::create(1.2f, scene,true);//翻页，后翻
//        
//    dscene=TransitionFadeTR::create(1.2f, scene);//向右上波浪
//    dscene=TransitionFadeBL::create(1.2f, scene);//向左下波浪
//    dscene=TransitionFadeUp::create(1.2f, scene);//向上百叶窗
//    dscene=TransitionFadeDown::create(1.2f, scene);//向下百叶窗
//    dscene=TransitionTurnOffTiles::create(1.2f, scene);//随机小方块
//    dscene=TransitionSplitRows::create(1.2f, scene);//按行切
//    dscene=TransitionSplitCols::create(1.2f, scene);//按列切
    
    director->replaceScene(dscene);
        
    return;
    
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
}
