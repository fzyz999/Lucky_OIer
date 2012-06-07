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

QList<pluginStruct> global::plugins[count];

global::global()
{
}

void global::global_init(QApplication *p)
{
    QCoreApplication::setOrganizationName("Lucky OIer Team");
    QCoreApplication::setApplicationName("Lucky OIer");
    QCoreApplication::setApplicationVersion("1.0.0.0");

    p->setWindowIcon(QIcon(":/images/images/Logo.png"));

    QSettings settings;

    settings.beginGroup("plugins");
    QStringList plugins_name(settings.value("list_of_name").toStringList());
    pluginStruct tmp;
    for(QStringList::iterator i=plugins_name.begin();i!=plugins_name.end();i++)
    {
        tmp.p_plder=new QPluginLoader(*i);
        if(tmp.p_plder->load())
        {
            tmp.p_plugin=tmp.p_plder->instance();
            plugins[settings.value(*i+"/type").toInt()].push_back(tmp);
        }
        else
            delete tmp.p_plder;
    }
    settings.endGroup();
}

void global::global_exit()
{
    for(int i=0;i<count;i++)
    {
        for(QList<pluginStruct>::iterator it=plugins[i].begin();it!=plugins[i].end();it++)
        {
            it->p_plder->unload();
            delete it->p_plder;
        }
    }
}

QList<pluginStruct>* global::get_plugins_list(plugin_types type)
{
    return &plugins[type];
}
