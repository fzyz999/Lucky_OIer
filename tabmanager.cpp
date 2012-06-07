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

#include "tabmanager.h"

TabManager::TabManager(QWidget *parent) :
    QTabWidget(parent)
{
    clear();
    setDocumentMode(true);
    setMovable(true);
    setTabsClosable(true);
    tab_count=1;
}

void TabManager::open_file()
{
    QSettings settings;
    QStringList file_name_list=QFileDialog::getOpenFileNames(this,tr("Open File"),settings.value("files/historyDir").toString());
    codeEditor *tmp;
    QString name;
    int i;

    if(!file_name_list.isEmpty())
    {
        name=*file_name_list.begin();

        for(i=name.size()-1;i>=0;i--)
            if(name[i]=='/')
                break;

        settings.setValue("files/historyDir",name.left(i));
    }

    while(!file_name_list.isEmpty())
    {
        name=*file_name_list.begin();

        tmp=new codeEditor(name,this);

        for(i=name.size()-1;i>=0;i--)
            if(name[i]=='/')
                break;
        name=name.right(name.size()-i-1);

        addTab(tmp,name);

        file_name_list.pop_front();
    }
}
