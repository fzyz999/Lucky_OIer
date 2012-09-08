#ifndef GCC_H
#define GCC_H

#include "compilerbase.h"

class GCC : public compilerBase
{
    Q_OBJECT
public:
    explicit GCC(QObject *parent = 0);

    void compile(const QString *filename);
    QVector<compileError>* get_compile_error();

    static void init(const QString& _path, const QStringList& _arguments);
    static void init(QString& _path, QStringList& _arguments);

private:
    static compilerInfo info;
    
signals:
    
public slots:
    
};

#endif // GCC_H
