#include "configerbase.h"

configerBase::configerBase(QWidget *parent) :
    QWidget(parent)
{
}

void configerBase::apply()
{
    return ;
}

QString configerBase::name()
{
    return tr("abstract configer");
}

QList<configerBase*> optionsDialog::configer_list;

optionsDialog::optionsDialog(QWidget *parent) :
    QDialog(parent, Qt::Dialog)
{
    setModal(true);

}

bool optionsDialog::add_configer(configerBase *configer)
{
    configer_list<<configer;

    return true;
}
