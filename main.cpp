#include <QCoreApplication>
#include <QString>
#include <QDebug>

#include "pref_handler/preferencehandler.h"
#include "core/mainthread.h"
#include "core/messagingbroadcaster.h"
#include "logger/logger.h"
#include "versions.h"

Logger *gLog = new Logger(); //init logger handler


MessagingBroadcaster *gMessageBroadcaster = new MessagingBroadcaster();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PreferenceHandler mPref(MAIN_CONFIG);
    MainThread *mMain;


    //Start and read base preferences
    gLog->log(__FILE__,"Adding Telemetry EVADTS Box started");
    gLog->log(__FILE__,"Loading main preferences...");

    if(!mPref.load())
    {
        gLog->log(__FILE__,"ERROR: Cannot load base preference, the application will now stop");
        return -1;
    }

    //now get the module list and print the module version
    gLog->log(__FILE__,"Main core v. "+QString(MAIN_VERSION));
#ifdef RS232HANDLER_VERSION
    gLog->log(__FILE__,"RS232 v. "+QString(RS232HANDLER_VERSION));
#endif
#ifdef ETHERNET_VERSION
    gLog->log(__FILE__,"Ethernet v. "+QString(ETHERNET_VERSION));
#endif

    mMain = new MainThread();

    Message msg;
    msg.ID = 1000;
    msg.payload.append(QVariant(QString("Prova payload1")));
    msg.payload.append(QVariant(QString("Prova payload2")));
    msg.payload.append(QVariant(QString("Prova payload3")));
    msg.payload.append(QVariant(QString("Prova payload4")));
    gMessageBroadcaster->postMessage(MessagingBroadcaster::MainThread,&msg);

    return a.exec();
}
