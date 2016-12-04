#ifndef MESSAGINGBROADCASTER_H
#define MESSAGINGBROADCASTER_H

#include <QObject>
#include <QVariant>
#include <QHash>
#include <QMutex>

class Message : public QObject
{
    Q_OBJECT
public:
    explicit Message(QObject *parent = 0);

    int ID;
    QList<QVariant> payload;
};

class MessagingBroadcaster : public QObject
{
    Q_OBJECT
public:
    explicit MessagingBroadcaster(QObject *parent = 0);

    typedef enum
    {
        MainThread,
        RS232Module,
        EVADTSModule,
        EthernetModule,
        MaxThreadIndexes
    }ThreadIndex;

    typedef enum
    {
        IndexNotFound,
        RegisterErr,
        MaxErr
    }MessagingError;

    bool registerListener(ThreadIndex threadIx, QList<Message*> *mailbox);
signals:
    void error(MessagingError err);
public slots:
    void postMessage(ThreadIndex address, Message *data);
private:
    QHash<ThreadIndex, QList<Message*>*> pBroadcastListener;
    QMutex mutex;
};

#endif // MESSAGINGBROADCASTER_H