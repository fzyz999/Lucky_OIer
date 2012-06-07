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

#ifndef LOP_PLUGINS_INTERFACE_H
#define LOP_PLUGINS_INTERFACE_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QString>
#include <QStringList>

class PluginInterface
{
public:
    virtual QString get_version();
};

//lop_mode_interface declare//
class lopModeInterface:public QPlainTextEdit,PluginInterface
{
public :
    virtual bool open_file(const QStringList *p_files);
    virtual bool close();
    virtual QWidget* get_config_dialog();
};

Q_DECLARE_INTERFACE(lopModeInterface,"Lucky.OIer/1.0")

////////////

//lop_compiler_interface declare
struct compileError
{
    QString error;
    int line_num;
};
class lopCompilerInterface:public PluginInterface
{
public:
    virtual bool compile(const QString *filename);
    virtual QVector<compileError>* get_compile_error();
};

Q_DECLARE_INTERFACE(lopCompilerInterface,"Lucky.OIer/1.0")

////////////


#endif // LOP_PLUGINS_INTERFACE_H
