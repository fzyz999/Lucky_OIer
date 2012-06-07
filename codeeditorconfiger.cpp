#include "codeeditorconfiger.h"
#include "ui_codeeditorconfiger.h"

codeEditorConfiger::codeEditorConfiger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::codeEditorConfiger)
{
    ui->setupUi(this);
}

codeEditorConfiger::~codeEditorConfiger()
{
    delete ui;
}
