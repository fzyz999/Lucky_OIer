#include "gcc.h"

GCC::GCC(QObject *parent) :
    compilerBase(parent)
{
}

compilerInfo GCC::info;

void GCC::init(const QString &_path, const QStringList &_arguments)
{
    info.arguments.clear();
    info.arguments=_arguments;
    int tmp=info.arguments.indexOf(QRegExp("-fmessage-length="));
    if(tmp!=-1)
    {
        info.arguments.removeAt(tmp);
        info.arguments<<"-fmessage-length=0";
    }

    info.path=_path;
}

void GCC::init(QString &_path, QStringList &_arguments)
{
    info.arguments.clear();
    info.arguments=_arguments;
    int tmp=info.arguments.indexOf(QRegExp("-fmessage-length="));
    if(tmp!=-1)
    {
        info.arguments.removeAt(tmp);
        info.arguments<<"-fmessage-length=0";
    }

    info.path=_path;
}

void GCC::compile(const QString *filename)
{
    info.arguments.push_back(*filename);
    start(info.path,info.arguments,QIODevice::ReadOnly);
    info.arguments.pop_back();
}

QVector<compileError>* GCC::get_compile_error()
{
    return NULL;
}
