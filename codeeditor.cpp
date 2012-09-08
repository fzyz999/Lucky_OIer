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
    isFileNameChanged=false;
}

codeEditor::codeEditor(const QString &name, QWidget *parent):
    QsciScintilla(parent)
{
    init();
    open(name);
    isFileNameChanged=false;
}

void codeEditor::init()
{
    setAutoIndent(true);
    //setAutoCompletionFillupsEnabled(true);
    //setAutoCompletionSource(AcsAll);
    //setAutoCompletionThreshold(3);
}

bool codeEditor::open(QString name)
{
    QFileInfo fileInfo;
    file.setFileName(name);
    fileInfo.setFile(file);

    if(file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        if(!read(&file))
        {
            file.close();
            file.setFileName("\0");
            return false;
        }

        setModified(false);

        name=fileInfo.suffix();
        if(name=="cpp"||name=="c")
            setLexer(new QsciLexerCPP);
        else if(name=="pas")
            setLexer(new QsciLexerPascal);

        file.close();

        return true;
    }

    file.setFileName("\0");

    return false;
}

bool codeEditor::save()
{
    if(file.fileName().isEmpty())
    {
        QSettings settings;
        file.setFileName(QFileDialog::getSaveFileName(
                             this,tr("Save File"),
                             settings.value("files/historyDir").toString()));

        //if getSaveFileName() is canceled by user
        if(file.fileName().isEmpty())
        {
            isFileNameChanged=false;
            return true;
        }
        //return true because canceling by user isn't an error

        isFileNameChanged=true;

        QFileInfo fileInfo(file);
        QString name=fileInfo.suffix();
        if(name=="cpp"||name=="c")
            setLexer(new QsciLexerCPP);
        else if(name=="pas")
            setLexer(new QsciLexerPascal);
    }

    if(file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        if(!write(&file))
        {
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}

bool codeEditor::close()
{
    if(isModified())
    {
        QMessageBox msgbox(this);

        msgbox.setText(tr("The document has been modified."));
        msgbox.setInformativeText(tr("Do you want to save your changes?"));
        msgbox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        msgbox.setDefaultButton(QMessageBox::Save);

        int ret=msgbox.exec();

        switch (ret)
        {
        case QMessageBox::Save:
            // Save was clicked
            if(!save())
            {
                //Save file failed
                msgbox.setText(tr("Saving file failed!"));
                msgbox.setInformativeText(tr("Please save it again"));
                msgbox.setStandardButtons(QMessageBox::Ok);
                msgbox.setDefaultButton(QMessageBox::Ok);
                msgbox.setIcon(QMessageBox::Warning);

                msgbox.exec();
                return false;
            }

            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            return true;

            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            return false;

            break;
        default:
            // should never be reached
            qWarning("codeeditor.cpp: switch(ret) reached an unexcepted line!");
            break;
        }
    }

    return true;
}

bool codeEditor::is_filename_changed()
{
    return isFileNameChanged;
}

QString codeEditor::get_file_name()
{
    QFileInfo fileInfo(file);
    return fileInfo.fileName();
}

void codeEditor::set_filename_changed(const bool &bl)
{
    isFileNameChanged=bl;
}
