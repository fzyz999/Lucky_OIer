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
    setAutoIndent(true);
    setAutoCompletionFillupsEnabled(true);
}

codeEditor::codeEditor(const QString &name, QWidget *parent):
    QsciScintilla(parent)
{
    open(name);
}

bool codeEditor::open(QString name)
{
    int i;
    QFile file;
    file.setFileName(name);
    if(file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        read(&file);
        for(i=name.size()-1;i>=0;i--)
            if(name[i]=='.')
                break;
        name=name.right(name.size()-i-1);
        if(name=="cpp"||name=="c")
            setLexer(new QsciLexerCPP);
        else if(name=="pas")
            setLexer(new QsciLexerPascal);
        return true;
    }

    return false;
}
