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

#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QWidget>
#include <QTabWidget>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QErrorMessage>
#include "global.h"
#include "codeeditor.h"
#include "configerbase.h"

namespace Ui{
class tabManagerConfiger;
}

class tabManagerConfiger : public configerBase
{
    Q_OBJECT

public:
    explicit tabManagerConfiger(QWidget *parent=0);
    ~tabManagerConfiger();

private:
    Ui::tabManagerConfiger *ui;

};

class TabManager : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabManager(QWidget *parent = 0);

public slots:
    void open_file();
    void new_file();
    void save();
    void save_all();
    //void text_changed();
    void redo();
    void undo();
    void copy();
    void cut();
    void paste();
    void select_all();
    void on_tab_close_requested(int index);
    void on_current_tab_change(int index);

private:
    int tab_count;
    int new_file_count;
    codeEditor *currentEditor;


};

#endif // TABMANAGER_H
