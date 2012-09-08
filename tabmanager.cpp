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

    connect(this,SIGNAL(tabCloseRequested(int)),this,SLOT(on_tab_close_requested(int)));
    connect(this,SIGNAL(currentChanged(int)),this,SLOT(on_current_tab_change(int)));

    setDocumentMode(true);
    setMovable(true);
    setTabsClosable(true);
    setElideMode(Qt::ElideRight);
    setTabPosition(QTabWidget::North);
    tab_count=1;
    new_file_count=1;
    currentEditor=NULL;

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
        addTab(tmp,tr("Untitled")+QString::number(new_file_count++));
    else
    {
        QErrorMessage error(this);
        error.showMessage(tr("out of memmory!"));
        error.exec();
    }
}

void TabManager::save()
{
    if(Q_LIKELY(currentEditor!=NULL))
        if(Q_UNLIKELY(!currentEditor->save()))
        {
            QErrorMessage error(this);
            error.showMessage(tr("Saving file failed!"));
            error.exec();
        }
        else if(currentEditor->is_filename_changed())
        {
            qDebug()<<currentEditor->get_file_name();
            setTabText(currentIndex(),currentEditor->get_file_name());
            currentEditor->set_filename_changed(false);
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
            else if(editor->is_filename_changed())
            {
                setTabText(i-1,editor->get_file_name());
            }
        }
    }
}

void TabManager::undo()
{
    if(Q_LIKELY(currentEditor!=NULL))
        currentEditor->undo();
}

void TabManager::redo()
{
    if(Q_LIKELY(currentEditor!=NULL))
        currentEditor->redo();
}

void TabManager::copy()
{
    if(Q_LIKELY(currentEditor!=NULL))
        currentEditor->copy();
}

void TabManager::cut()
{
    if(Q_LIKELY(currentEditor!=NULL))
        currentEditor->cut();
}

void TabManager::paste()
{
    if(Q_LIKELY(currentEditor!=NULL))
        currentEditor->paste();
}

void TabManager::select_all()
{
    if(Q_LIKELY(currentEditor!=NULL))
        currentEditor->selectAll();
}

void TabManager::on_tab_close_requested(int index)
{
    codeEditor *tab=qobject_cast<codeEditor *>(widget(index));

    if(tab->close())
    {
            removeTab(index);
            tab->deleteLater();
    }
}

void TabManager::on_current_tab_change(int index)
{
    currentEditor=qobject_cast<codeEditor *>(widget(index));
}
