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
