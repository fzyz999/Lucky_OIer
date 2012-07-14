#ifndef CONFIGERBASE_H
#define CONFIGERBASE_H

#include <QWidget>
#include <QDialog>
#include <QList>

class configerBase : public QWidget
{
    Q_OBJECT
public:
    explicit configerBase(QWidget *parent = 0);
    virtual QString name();
    
signals:
    
public slots:
    virtual void apply();
    
};

Q_DECLARE_INTERFACE(configerBase,"Lucky.OIer/1.0")

class optionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit optionsDialog(QWidget *parent = 0);
    static bool add_configer(configerBase* configer);

private:
    static QList<configerBase*> configer_list;

};

#endif // CONFIGERBASE_H
