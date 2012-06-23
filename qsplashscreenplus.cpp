#include "qsplashscreenplus.h"

QSplashScreenPlus::QSplashScreenPlus(const QPixmap &pixmap, const int &min_splash_time) :
    QSplashScreen(pixmap)
{
    _min_splash_time=min_splash_time;
    show();
    show_animation(0.0,1.0);
}

QSplashScreenPlus::QSplashScreenPlus(QWidget *parent, const QPixmap &pixmap, const int &min_splash_time) :
    QSplashScreen(parent,pixmap)
{
    _min_splash_time=min_splash_time;
    show();
    show_animation(0.0,1.0);
}

QSplashScreenPlus::QSplashScreenPlus(const QString &pixmap_addr, const int &min_splash_time)
{
    _min_splash_time=min_splash_time;
    show();
    QPixmap pixmap(pixmap_addr);
    setPixmap(pixmap);
    show_animation(0.0,1.0);
}

QSplashScreenPlus::QSplashScreenPlus(QWidget *parent, const QString &pixmap_addr, const int &min_splash_time) :
    QSplashScreen(parent)
{
    _min_splash_time=min_splash_time;
    show();
    QPixmap pixmap(pixmap_addr);
    setPixmap(pixmap);
    show_animation(0.0,1.0);
}

void QSplashScreenPlus::show_animation(const qreal &start,const qreal &end)
{
    setGraphicsEffect(&effect);

    QPropertyAnimation *animation = new QPropertyAnimation(&effect, "opacity");
    animation->setParent(this);

    animation->setDuration(_min_splash_time);
    animation->setStartValue(start);
    animation->setEndValue(end);

    animation->start();
}
