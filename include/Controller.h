/**
    Provide by Walon Li, YJ Fang

    File Controller.h
**/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <boost/thread.hpp>
#include <QGraphicsView>
#include <QDebug>
#include <QColor>
#include "Frame.h"
#include "IPlay.h"
#include "PdrBasic.h"

namespace pdr
{
class Controller : public IPlay
{
public:
    static pdr::Controller * getInstance();

    void addFrame(Frame *frame);

    template <typename Iterator>
    void addFrame(Iterator first, Iterator last);

    void setBGColor(QColor c) { bg_color = c; }
    void setBGFile(std::string s) { bg_music_file = s; }
    void setParentWidget(QWidget *w) { parent = w; }
    void setGraphicsView(QGraphicsView *v) { view = v; }

    QColor getBGColor() const { return bg_color; }
    std::string getBGMusicFile() const { return bg_music_file; }
    QWidget *getParentWidget() const { return parent; }
    QGraphicsView *getGraphicsView() const { return view; }

    void play() ;
    void stop() ;
    void forward(){}
    void backward(){}

    void resetController() ;

private:
    Controller();
    ~Controller();

private:
    std::vector<Frame*> frames ;
    std::vector<boost::thread*> threads ;

    QColor bg_color ;
    std::string bg_music_file ;

    // Belong to view systme, don't free it.
    QWidget *parent ;
    QGraphicsView *view ;
};
}

#include "include/Controller.tcc"

#endif
