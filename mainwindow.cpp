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
    menu->addAction(tr("open"),p_tabmgr,SLOT(open_file()),QKeySequence(QKeySequence::Open));
    menu->addSeparator();
    menu->addAction(tr("quit"),this,SLOT(close()),QKeySequence(QKeySequence::Quit));
    menubar->addMenu(menu);

    menu=new QMenu(tr("help"),menubar);
    menu->addAction(tr("about"),this,SLOT(about_dialog()));
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
