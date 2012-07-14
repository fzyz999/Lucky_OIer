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

#include "ui_tabmanagerconfiger.h"

tabManagerConfiger::tabManagerConfiger(QWidget *parent) :
    configerBase(parent),
    ui(new Ui::tabManagerConfiger)
{
    ui->setupUi(this);
}

tabManagerConfiger::~tabManagerConfiger()
{
    delete ui;
}

TabManager::TabManager(QWidget *parent) :
    QTabWidget(parent)
{
    clear();
    setDocumentMode(true);
    setMovable(true);
    setTabsClosable(true);
    setElideMode(Qt::ElideRight);
    setTabPosition(QTabWidget::East);
    tab_count=1;
    new_file_count=1;
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

        name=QFileInfo(name).fileName();

        addTab(tmp,name);

        file_name_list.pop_front();
    }
}

void TabManager::new_file()
{
    codeEditor *tmp=new codeEditor(this);
    if(tmp!=NULL)
        addTab(tmp,tr("Unnamed")+QString::number(new_file_count++));
    else
    {
        QErrorMessage error(this);
        error.showMessage(tr("out of memmory!"));
        error.exec();
    }
}

void TabManager::save()
{
    codeEditor *current=qobject_cast<codeEditor*>(currentWidget());

    if(Q_LIKELY(current!=NULL))
        if(Q_UNLIKELY(!current->save()))
        {
            QErrorMessage error(this);
            error.showMessage(tr("Saving file failed!"));
            error.exec();
        }
}

void TabManager::save_all()
{
    for(int i=count();i>0;i--)
    {
        codeEditor *editor=qobject_cast<codeEditor *>(widget(i-1));

        if(Q_LIKELY(editor!=NULL))
        {
            if(Q_UNLIKELY(!editor->save()))
            {
                QErrorMessage error(this);
                error.showMessage(tr("Saving file failed!"));
                error.exec();
            }
        }


    }
}

void TabManager::undo()
{
    codeEditor *current=qobject_cast<codeEditor *>(currentWidget());

    if(Q_LIKELY(current!=NULL))
        current->undo();
}

void TabManager::redo()
{
    codeEditor *current=qobject_cast<codeEditor *>(currentWidget());

    if(Q_LIKELY(current!=NULL))
        current->redo();
}

void TabManager::copy()
{
    codeEditor *current=qobject_cast<codeEditor *>(currentWidget());

    if(Q_LIKELY(current!=NULL))
        current->copy();
}

void TabManager::cut()
{
    codeEditor *current=qobject_cast<codeEditor *>(currentWidget());

    if(Q_LIKELY(current!=NULL))
        current->cut();
}

void TabManager::paste()
{
    codeEditor *current=qobject_cast<codeEditor *>(currentWidget());

    if(Q_LIKELY(current!=NULL))
        current->paste();
}

void TabManager::select_all()
{
    codeEditor *current=qobject_cast<codeEditor *>(currentWidget());

    if(Q_LIKELY(current!=NULL))
        current->selectAll();
}
