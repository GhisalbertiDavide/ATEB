#include "preferencehandler.h"
#include "logger/logger.h"

extern logger *gLog;

PreferenceHandler::PreferenceHandler(QString pref_file_path, QObject *parent) : QObject(parent)
{
    current_pref_file.setFileName(pref_file_path);
    if(!current_pref_file.open(QIODevice::ReadWrite))
        gLog->log(__FILE__,"Cannot open pref file ["+pref_file_path+"]");
}
