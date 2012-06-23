#ifndef CODEEDITORCONFIGER_H
#define CODEEDITORCONFIGER_H

#include <QWidget>
#include <Qsci/qsciscintilla.h>

namespace Ui {
class codeEditorConfiger;
}

struct codeEditorSettings
{
    QsciScintilla::AnnotationDisplay annotation_display_style;
    QsciScintilla::FoldStyle fold;
    bool autoInd;
    QsciScintilla::BraceMatch braceMode;
    QsciScintilla::AutoCompletionSource acSource;
    QsciScintilla::CallTipsStyle call_tips_style;
    QsciScintilla::AutoCompletionUseSingle use_single;
    QColor nl_text_colour;
    QColor nl_paper_colour;
    bool fillups_enabled;
};

class codeEditorConfiger : public QWidget
{
    Q_OBJECT

public slots:
    void settings_accept();
    
signals:
    //emit a signal when user changed settings and clicked the "accept" button
    void settings_changed(codeEditorSettings* ce_settings);

public:
    explicit codeEditorConfiger(QWidget *parent = 0);
    ~codeEditorConfiger();
    
private:
    Ui::codeEditorConfiger *ui;
    codeEditorSettings settings;
};

#endif // CODEEDITORCONFIGER_H
