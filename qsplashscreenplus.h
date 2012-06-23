#ifndef QSPLASHSCREENPLUS_H
#define QSPLASHSCREENPLUS_H

#include <QSplashScreen>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QElapsedTimer>
#include <QApplication>

class QSplashScreenPlus : public QSplashScreen
{
    Q_OBJECT
public:
    explicit QSplashScreenPlus(const QPixmap & pixmap = QPixmap(), const int &min_splash_time=3000);
    explicit QSplashScreenPlus(QWidget * parent, const QPixmap & pixmap = QPixmap(), const int &min_splash_time=3000);
    explicit QSplashScreenPlus(const QString &pixmap_addr, const int &min_splash_time=3000);
    explicit QSplashScreenPlus(QWidget * parent, const QString &pixmap_addr, const int &min_splash_time=3000);
    
signals:
    
public slots:

private:
    QGraphicsOpacityEffect effect;

    int _min_splash_time;
    void show_animation(const qreal &start,const qreal &end);
    
};

#endif // QSPLASHSCREENPLUS_H
