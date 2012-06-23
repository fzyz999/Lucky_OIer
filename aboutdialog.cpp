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

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
    setLayout(ui->verticalLayout);

    QFile file;

    file.setFileName(":/text/gpl-3.0.html");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        license=new QString(file.readAll());
    file.close();

    file.setFileName(":/text/readme.html");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        about=new QString(file.readAll());
    file.close();

    file.setFileName(":/text/authors.txt");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        authors=new QString(file.readAll());
    file.close();

    ui->textBrowser->setText(*about);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}

//about button
void aboutDialog::on_pushButton_4_clicked()
{
    ui->textBrowser->setHtml(*about);
}

//authors button
void aboutDialog::on_pushButton_2_clicked()
{
    ui->textBrowser->setPlainText(*authors);
}

//license button
void aboutDialog::on_pushButton_3_clicked()
{
    ui->textBrowser->setHtml(*license);
}

//ok button
void aboutDialog::on_pushButton_clicked()
{
    accept();
}
