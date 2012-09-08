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

#include "global.h"

//QList<pluginStruct> global::plugins[count];

global::global()
{
}

void global::global_init(QApplication *p)
{
    QElapsedTimer t;

    QSplashScreenPlus splash(":/images/images/Splash.png");

    //loading version and setting basic infomations
    t.start();
    splash.showMessage("loading basic infomations",Qt::AlignRight,QColor(Qt::white));
    qApp->processEvents();

    QFile version(":/text/version.txt");

    Q_ASSERT(version.open(QIODevice::ReadOnly|QIODevice::Text));
    QCoreApplication::setApplicationVersion(QString(version.readAll()));

    QCoreApplication::setOrganizationName("Lucky OIer Team");
    QCoreApplication::setApplicationName("Lucky OIer");

    p->setWindowIcon(QIcon(":/images/images/Logo.png"));

    while(t.elapsed()<1000)
        qApp->processEvents();

    QSettings settings;

    //loading compiler
    t.restart();
    splash.showMessage("finding compiler",Qt::AlignRight,QColor(Qt::white));
    qApp->processEvents();

    settings.beginGroup("compiler");
#ifdef Q_OS_WIN32
    QFileInfo file_info(settings.value("gcc/path","C:/MinGW/bin/gcc").toString());
#else
    QFileInfo file_info(settings.value("gcc/path","/usr/bin/gcc").toString());
#endif
    while(!file_info.exists())
    {
        file_info.setFile(QInputDialog::getText(0,tr("compiler path"),tr("please input the path of gcc")));
    }

    GCC::init(file_info.filePath(),settings.value("gcc/args").toStringList());

    settings.endGroup();

    while(t.elapsed()<1000)
        qApp->processEvents();

    /*loading plugins
    t.restart();
    splash.showMessage("loading plugins",Qt::AlignRight,QColor(Qt::white));
    qApp->processEvents();

    settings.beginGroup("plugins");
    QStringList plugins_name(settings.value("list_of_name").toStringList());
    pluginStruct tmp;
    for(QStringList::iterator i=plugins_name.begin();i!=plugins_name.end();i++)
    {
        tmp.p_plder=new QPluginLoader(*i);
        if(tmp.p_plder->load())
        {
            tmp.p_plugin=tmp.p_plder->instance();
            qobject_cast<PluginInterface*> (tmp.p_plugin)->init();
            plugins[settings.value(*i+"/type").toInt()].push_back(tmp);
        }
        else
            delete tmp.p_plder;
    }
    settings.endGroup();

    while(t.elapsed()<1000)
        qApp->processEvents();*/

    //loading gui styles
    t.restart();
    splash.showMessage("loading gui styles",Qt::AlignRight,QColor(Qt::white));
    qApp->processEvents();

    settings.beginGroup("guiStyle");
    p->setStyle(settings.value("styleName").toString());
    settings.endGroup();

    while(t.elapsed()<1000)
        qApp->processEvents();

    splash.close();
}

void global::global_exit()
{
    /*for(int i=0;i<count;i++)
    {
        for(QList<pluginStruct>::iterator it=plugins[i].begin();it!=plugins[i].end();it++)
        {
            it->p_plder->unload();
            delete it->p_plder;
        }
    }*/
}

/*QList<pluginStruct>* global::get_plugins_list(plugin_types type)
{
    return &plugins[type];
}*/
