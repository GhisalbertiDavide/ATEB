#include "mainthread.h"
#include "logger/logger.h"

extern Logger *gLog;

MainThread::MainThread(QObject *parent) : QObject(parent)
{
    mThread = new QThread();

    this->moveToThread(mThread);
    connect(mThread,SIGNAL(finished()),this,SLOT(deleteLater()));
    connect(mThread,SIGNAL(started()),this,SLOT(proc()));
    mThread->start();
}

void MainThread::proc()
{
    while(true)
    {
        this->thread()->sleep(1);
        gLog->log(__FILE__,"Thread running");
    }
}