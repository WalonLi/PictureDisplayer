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
#include <QThread>
#include <QMediaPlayer>
#include <QDir>
#include <QObject>
#include <boost/format.hpp>
#include "Frame.h"
#include "IPlay.h"
#include "PlayerWindow.h"
#include "SelectorWindow.h"


namespace pdr
{

class Controller : public QObject, public IPlay
{
    Q_OBJECT

public:
    static pdr::Controller * getInstance();

    enum state
    {
        CTRL_PLAY = 0,
        CTRL_PAUSE,
        CTRL_STOP,
    };

    // Add method
    void addFrame(pdr::Frame *frame);

    template <typename Iterator>
    void addFrame(Iterator first, Iterator last);



    // Set method
    void setBGColor(const QColor c)
    {
        bg_color_ = c;
        if (view_) view_->setBackgroundBrush(bg_color_);
    }

    void setBGMusic(const std::string &s)
    {
        std::string path = (boost::format("%s/%s")
                            % QDir::currentPath().toStdString()
                            % s).str() ;
        bg_music_player_.setMedia(QMediaContent(QUrl::fromLocalFile(path.c_str())));
    }

    void setBGMusic(const QMediaContent &media)
        {bg_music_player_.setMedia(media);}

    void setGraphicsView(QGraphicsView *v)
        { view_ = v; }

    void setSelectorWindow(SelectorWindow *w)
        { s_window_ = w; }

    void setPlayerWindow(PlayerWindow *w)
        { p_window_ = w; }



    // Get method
    const QColor getBGColor() const { return bg_color_; }
    const QMediaContent getBGMusic() const {return bg_music_player_.currentMedia();}
    QGraphicsView *getGraphicsView() const { return view_; }
    state getState() const { return state_; }

    void play() ;
    void pause() ;
    void resume() ;
    void stop() ;
    void forward(){}
    void backward(){}

    void resetFrames() ;

signals:
    void playCompSignals(Component*) ;
    void pauseCompSignals(Component*) ;
    void resumeCompSignals(Component*) ;
    void stopCompSignals(Component*) ;

    void endPlaySignals() ;

private:
    Controller();
    ~Controller();


private:
    std::vector<pdr::Frame*> frames_ ;

    QColor bg_color_ ;
    QMediaPlayer bg_music_player_ ;

    // controller state
    state state_ ;

    // Belong to view systme, don't free it.
    QGraphicsView *view_ ;
    SelectorWindow *s_window_ ;
    PlayerWindow *p_window_ ;
};
}

#include "include/Controller.tcc"

#endif
