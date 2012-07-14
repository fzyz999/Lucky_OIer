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

#include "codeeditor.h"

codeEditor::codeEditor(QWidget *parent):
    QsciScintilla(parent)
{
    init();
}

codeEditor::codeEditor(const QString &name, QWidget *parent):
    QsciScintilla(parent)
{
    init();
    open(name);
}

void codeEditor::init()
{
    setAutoIndent(true);
    setAutoCompletionFillupsEnabled(true);

    file_path.clear();
}

bool codeEditor::open(QString name)
{
    QFile file;
    QFileInfo fileInfo;
    file.setFileName(name);
    fileInfo.setFile(file);

    if(file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        if(!read(&file))
            return false;

        file_path=name;

        name=fileInfo.suffix();
        if(name=="cpp"||name=="c")
            setLexer(new QsciLexerCPP);
        else if(name=="pas")
            setLexer(new QsciLexerPascal);
        return true;
    }

    return false;
}

bool codeEditor::save()
{
    QFile file;
    if(file_path.isEmpty())
    {
        QSettings settings;
        file.setFileName(QFileDialog::getSaveFileName(
                             this,tr("Save File"),
                             settings.value("files/historyDir").toString()));
    }
    else
    {
        file.setFileName(file_path);
    }

    if(file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        if(!write(&file))
            return false;
    }

    return true;
}

void codeEditor::close()
{
    if(isModified())
    {
        QMessageBox msgbox(this);

        msgbox.setText(tr("The document has been modified."));
        msgbox.setInformativeText(tr("Do you want to save your changes?"));
        msgbox.setDefaultButton(QMessageBox::Save);
        msgbox.setStandardButtons(QMessageBox::Discard|QMessageBox::Cancel);

        int ret=msgbox.exec();

        switch (ret)
        {
        case QMessageBox::Save:
            // Save was clicked
            if(!save())
            {
                //Save file failed

            }

            break;
        case QMessageBox::Discard:
            // Don't Save was clicked


            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            return ;

            break;
        default:
            // should never be reached
            qWarning("codeeditor.cpp: switch(ret) reached an unexcepted code!");
            break;
        }
    }



    deleteLater();
}
