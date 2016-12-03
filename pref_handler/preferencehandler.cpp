#include "preferencehandler.h"
#include "logger/logger.h"

extern Logger *gLog;

PreferenceHandler::PreferenceHandler(QString pref_file_path, QObject *parent) : QObject(parent)
{
    current_pref_file.setFileName(pref_file_path);
    if(!current_pref_file.open(QIODevice::ReadWrite))
        gLog->log(__FILE__,"Cannot open pref file ["+pref_file_path+"]");
}

bool PreferenceHandler::load()
{
    QTextStream stream(&current_pref_file);
    QString line;

    gLog->log(__FILE__,"Loading preferences from ["+current_pref_file.fileName()+"]");

    if(!current_pref_file.isOpen())
        return false;

    do
    {
        line = stream.readLine();

        if(line.indexOf("[") == -1) //skip header
        {
            QStringList token = line.split("=");
            if(token.count() == 2)
            {
                pref_map.insert(token.at(0),token.at(1)); //insert preference as key-value
                gLog->log(__FILE__,"Pref key "+token.at(0)+" -> "+token.at(1));
            }
            else
                gLog->log(__FILE__,"Skipped property ["+line+"]: invalid format");
        }
    }while(!line.isNull());

    return true;
}
