#include "logger.h"
#include <QDateTime>
#include <QDebug>
#include <iostream>

logger::logger(QObject *parent) : QObject(parent)
{
    logFile.setFileName("log");
    if(!logFile.open(QIODevice::WriteOnly))
        qDebug()<<"ERROR Cannot open log file! No output will be written on disk";
    else
        filestream.setDevice(&logFile);
}

void logger::log(QString origin,QString string)
{
    QString log_string;

    log_string = "["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"] <"+origin+"> "+string;
    filestream<<log_string<<endl;
    std::cout<<log_string.toUtf8().data()<<std::endl;
}
