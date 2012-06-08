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

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QFile>
#include <QString>

namespace Ui {
class aboutDialog;
}

class aboutDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit aboutDialog(QWidget *parent = 0);
    ~aboutDialog();
    
private slots:
    //about button
    void on_pushButton_4_clicked();
    //authors button
    void on_pushButton_2_clicked();
    //license button
    void on_pushButton_3_clicked();
    //ok button
    void on_pushButton_clicked();

private:
    Ui::aboutDialog *ui;
    QString *about,*authors,*license;
};

#endif // ABOUTDIALOG_H
