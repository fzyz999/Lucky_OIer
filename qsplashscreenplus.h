/*
 * This file is part of Lucky OIer
 *
 * Copyright (C) 2012 by Wang Luming <wlm199558@126.com>
 *
 * Lucky OIer is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Lucky OIer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Lucky OIer. If not, see <http://www.gnu.org/licenses/>.
 */

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
