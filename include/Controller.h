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

    void addFrame(pdr::Frame *frame);

    template <typename Iterator>
    void addFrame(Iterator first, Iterator last);

    void setBGColor(QColor c) { bg_color_ = c; }
    void setBGFile(std::string s) { bg_music_file_ = s; }
    void setParentWidget(QWidget *w) { parent_ = w; }
    void setGraphicsView(QGraphicsView *v) { view_ = v; }

    QColor getBGColor() const { return bg_color_; }
    std::string getBGMusicFile() const { return bg_music_file_; }
    QWidget *getParentWidget() const { return parent_; }
    QGraphicsView *getGraphicsView() const { return view_; }

    void play() ;
    void stop() ;
    void forward(){}
    void backward(){}

    void resetController() ;

private:
    Controller();
    ~Controller();

private:
    std::vector<pdr::Frame*> frames_ ;
    std::vector<boost::thread*> threads_ ;

    QColor bg_color_ ;
    std::string bg_music_file_ ;

    // Belong to view systme, don't free it.
    QWidget *parent_ ;
    QGraphicsView *view_ ;
};
}

#include "include/Controller.tcc"

#endif
