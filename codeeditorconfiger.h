#ifndef CODEEDITORCONFIGER_H
#define CODEEDITORCONFIGER_H

#include <QWidget>

namespace Ui {
class codeEditorConfiger;
}

class codeEditorConfiger : public QWidget
{
    Q_OBJECT
    
public:
    explicit codeEditorConfiger(QWidget *parent = 0);
    ~codeEditorConfiger();
    
private:
    Ui::codeEditorConfiger *ui;
};

#endif // CODEEDITORCONFIGER_H
