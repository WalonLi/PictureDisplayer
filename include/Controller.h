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
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
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

    void setBGColor(QColor c)
    {
        bg_color_ = c;
        if (view_) view_->setBackgroundBrush(bg_color_);
    }

    void setBGMusic(std::string s)
    {
        bg_music_player_.setMedia(QMediaContent(QUrl::fromLocalFile(s.c_str()))) ;
    }
    void setBGMusic(QMediaContent media)
    {
        bg_music_player_.setMedia(media) ;
    }

    void setParentWidget(QWidget *w) { parent_ = w; }
    void setGraphicsView(QGraphicsView *v) { view_ = v; }

    QColor getBGColor() const { return bg_color_; }

    QMediaContent getBGMusic() const
    {
        return bg_music_player_.currentMedia();
    }

    QWidget *getParentWidget() const { return parent_; }
    QGraphicsView *getGraphicsView() const { return view_; }

    void play() ;
    void stop() ;
    void forward(){}
    void backward(){}

    void resetFrames() ;
    void resetThreads() ;

private:
    Controller();
    ~Controller();

private:
    std::vector<pdr::Frame*> frames_ ;
    std::vector<boost::thread*> threads_ ;

    QColor bg_color_ ;
    QMediaPlayer bg_music_player_ ;

    // Belong to view systme, don't free it.
    QWidget *parent_ ;
    QGraphicsView *view_ ;
};
}

#include "include/Controller.tcc"

#endif
