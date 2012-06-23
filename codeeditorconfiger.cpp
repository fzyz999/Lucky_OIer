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

void codeEditorConfiger::settings_accept()
{
    switch(ui->comboBox->currentIndex())
    {
    case 0:
        settings.annotation_display_style=QsciScintilla::AnnotationHidden;
    case 1:
        settings.annotation_display_style=QsciScintilla::AnnotationStandard;
    default:
        settings.annotation_display_style=QsciScintilla::AnnotationBoxed;
    }

    emit settings_changed(&settings);
}
