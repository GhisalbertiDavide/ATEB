#include <QString>

#include "messagingbroadcaster.h"
#include "logger/logger.h"
#include "versions.h"

extern Logger *gLog;

MessagingBroadcaster::MessagingBroadcaster(QObject *parent) : QObject(parent)
{

}

bool MessagingBroadcaster::registerListener(ThreadIndex threadIx, QList<Message *> *mailbox)
{
    mutex.lock();
    bool res = false;
    if(!pBroadcastListener.contains(threadIx))
    {
        pBroadcastListener.insert(threadIx,mailbox);
        gLog->log(__FILE__,"registerListener: added listener for thread "+itostr(threadIx));
        res = true;
    }
    else
    {
        gLog->log(__FILE__,"registerListener: Warning: Thread ix "+itostr(threadIx)+" already registered");
        res = false;
    }
    mutex.unlock();
    return res;
}

void MessagingBroadcaster::postMessage(ThreadIndex address, Message *data)
{
    QList<Message *> *pBox;

    mutex.lock();
    pBox = pBroadcastListener.value(address,NULL);
    if(pBox != NULL)
    {
        gLog->log(__FILE__,"postMessage: posting MessageID " + itostr(data->ID) + " with " + itostr(data->payload.count()));
        pBox->append(data);
    }
    else
    {
        gLog->log(__FILE__,"postMessage: ERROR the selected thread ("+itostr(address)+") is not registered");
        emit error(IndexNotFound);
    }
    mutex.unlock();
}
