# Known Issue or Something

1. Transparent player window and button(Limitation now, please see 1/2 history)
2. Finish Spinner bar(Selector->Player animation)
3. Parser and FileSelector
4. Run fail with QT5.4
5. [Critical] Sometimes, program will crash when click close button, but it very hard to duplicate issue. 

----

# UML

![](https://raw.githubusercontent.com/WalonLi/PictureDisplayer/Meeting/doc/UML.png)

----

# History
## 15/01/18
1. Finish pause/resume feature, works good :)
2. Understand how to do a animation(see PictureComponent.cpp)
3. Finish button's animation
4. Finish TextComponent.h/cpp
5. Integrate Effective obj into component, and finish LinearMoveEffect animation.

## 15/01/15
1. We don't have good idea with Pause/Continue feature now.  

## 15/01/08
1. Simple controller is done, it can play two pictures and background music

## 14/12/31
1. Finish Picture display(demo version) in Player.cpp
2. CentOS(VM) not support opacity now, I will try it on Windows later...
3. Use QGraphicView, QGraphicsScene, QGraphicsItem to implement show widget/component now.
   Every componet should be inherit QGraphicsItem as good.

## 14/12/31
1. Controller/Frame/Component interface is done.
2. Basic Selector and Player window is done.
3. Now, we need a demo that can be display picture, background music.

## 14/12/25
1. Project Name: PictureDisplayer(pdr)
2. Update UML(Component/Effective)
3. Coding Style have been checked.

## 14/12/23
1. Architecture discussion
2. JSON Parser(https://github.com/hjiang/jsonxx)
3. Controller is singlton, and it will assgin child thread to each component to play.
4. Update basic UML

## 14/12/22
1. Basic Layout in Layout.png
2. Use JSON style to write config.
3. FrameWork Qt5.2, Boost 1.57.0
