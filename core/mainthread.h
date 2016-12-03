#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QObject>
#include <QThread>

class MainThread : public QObject
{
    Q_OBJECT
public:
    explicit MainThread(QObject *parent = 0);

signals:

public slots:
    void proc();

private:
    QThread *mThread;
};

#endif // MAINTHREAD_H