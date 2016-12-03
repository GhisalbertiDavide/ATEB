#include <QCoreApplication>
#include <QString>
#include "logger/logger.h"
#include "versions.h"

logger *gLog = new logger(); //init logger handler

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Print modules version
    gLog->log(__FILE__,"Adding Telemetry EVADTS Box started");
    gLog->log(__FILE__,"Main core v. "+QString(MAIN_VERSION));
#ifdef RS232HANDLER_VERSION
    gLog->log(__FILE__,"RS232 v. "+QString(RS232HANDLER_VERSION));
#endif
#ifdef ETHERNET_VERSION
    gLog->log(__FILE__,"Ethernet v. "+QString(ETHERNET_VERSION));
#endif

    return a.exec();
}
