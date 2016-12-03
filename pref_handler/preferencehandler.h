#ifndef PREFERENCEHANDLER_H
#define PREFERENCEHANDLER_H

#include <QObject>
#include <QVariant>
#include <QFile>

class PreferenceHandler : public QObject
{
    Q_OBJECT
public:
    explicit PreferenceHandler( QString pref_file_path, QObject *parent = 0);

    QVariant getPref(QString pref_name);
    bool setPref(QString pref_name, QVariant pref_value);
    bool updatePrefOnDisk(void);
signals:

public slots:
private:
    QFile current_pref_file;
};

#endif // PREFERENCEHANDLER_H
