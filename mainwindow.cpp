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

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    read_settings();
    p_tabmgr=new TabManager(this);
    setCentralWidget(p_tabmgr);

    create_menu();
}

MainWindow::~MainWindow()
{
    write_settings();
}

void MainWindow::about_dialog()
{
    aboutDialog aboutdlg(this);
    aboutdlg.exec();
}

void MainWindow::create_menu()
{
    QMenuBar *menubar=new QMenuBar(this);

    QMenu *menu=new QMenu(tr("file"),menubar);
    menu->addAction(tr("new"),p_tabmgr,SLOT(new_file()),QKeySequence(QKeySequence::New));
    menu->addAction(tr("open"),p_tabmgr,SLOT(open_file()),QKeySequence(QKeySequence::Open));
    menu->addSeparator();
    menu->addAction(tr("save"),p_tabmgr,SLOT(save()),QKeySequence(QKeySequence::Save));
    menu->addAction(tr("save all"),p_tabmgr,SLOT(save_all()));
    menu->addSeparator();
    menu->addAction(tr("quit"),this,SLOT(close()),QKeySequence(QKeySequence::Quit));
    menubar->addMenu(menu);


    menu=new QMenu(tr("edit"),menubar);
    menu->addAction(tr("redo"),p_tabmgr,SLOT(redo()),QKeySequence(QKeySequence::Redo));
    menu->addAction(tr("undo"),p_tabmgr,SLOT(undo()),QKeySequence(QKeySequence::Undo));
    menu->addSeparator();
    menu->addAction(tr("cut"),p_tabmgr,SLOT(cut()),QKeySequence(QKeySequence::Cut));
    menu->addAction(tr("copy"),p_tabmgr,SLOT(copy()),QKeySequence(QKeySequence::Copy));
    menu->addAction(tr("paste"),p_tabmgr,SLOT(paste()),QKeySequence(QKeySequence::Paste));
    menu->addAction(tr("select all"),p_tabmgr,SLOT(paste()),QKeySequence(QKeySequence::SelectAll));
    /* TODO: options menu
    menu->addAction(tr("options"));*/
    menubar->addMenu(menu);

    menu=new QMenu(tr("help"),menubar);
    menu->addAction(tr("about"),this,SLOT(about_dialog()));
    menu->addAction(tr("about Qt"),this,SLOT(about_qt()));
    menubar->addMenu(menu);

    setMenuBar(menubar);
}

void MainWindow::read_settings()
{
    QSettings settings;
    settings.beginGroup("mainwindow");
    resize(settings.value("windowSize",QSize(600,500)).toSize());
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();
}

void MainWindow::write_settings()
{
    QSettings settings;
    settings.beginGroup("mainwindow");
    settings.setValue("windowSize",size());
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.endGroup();
}

void MainWindow::about_qt()
{
    QMessageBox::aboutQt(this);
}
