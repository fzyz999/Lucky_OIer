#ifndef COMPILERBASE_H
#define COMPILERBASE_H

#include <QProcess>

struct compileError
{
    QString error;
    int line_num;
};

class compilerBase : public QProcess
{
    Q_OBJECT

public:
    explicit compilerBase(QObject *parent = 0);

    virtual void compile(const QString *filename){}
    virtual QVector<compileError>* get_compile_error(){return NULL;}

signals:
    
public slots:
};

inline compilerBase::compilerBase(QObject *parent):
    QProcess(parent)
{

}

class compilerInfo
{
public:
    QString path;
    QStringList arguments;

};


#endif // COMPILERBASE_H
