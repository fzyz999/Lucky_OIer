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

#ifndef GLOBAL_H
#define GLOBAL_H

#include <QList>
#include <QStringList>
#include <QSettings>
#include <QPluginLoader>
#include <QVariant>
#include <QCoreApplication>
#include <QIcon>
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QElapsedTimer>
#include <QColor>
#include <QString>

#include "qsplashscreenplus.h"

enum plugin_types
{
    text_mode,
    compiler,
    debuger,
    other,
    count
};

struct pluginStruct
{
    QPluginLoader *p_plder;
    QObject *p_plugin;
};

class global
{
public:
    static QList<pluginStruct>* get_plugins_list(plugin_types type);
    static void global_init(QApplication *p);
    static void global_exit();

private:
    global();
    static QList<pluginStruct> plugins[count];
};

#endif // GLOBAL_H
