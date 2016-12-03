#ifndef PREFERENCEHANDLER_H
#define PREFERENCEHANDLER_H

#include <QObject>
#include <QVariant>
#include <QFile>
#include <QHash>

class PreferenceHandler : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief PreferenceHandler
     * @param pref_file_path
     * @param parent
     */
    explicit PreferenceHandler( QString pref_file_path, QObject *parent = 0);

    /**
     * @brief load
     * @return
     */
    bool load();

    /**
     * @brief getPref
     * @param pref_name
     * @return
     */
    QVariant getPref(QString pref_name);

    /**
     * @brief setPref
     * @param pref_name
     * @param pref_value
     * @return
     */
    bool setPref(QString pref_name, QVariant pref_value);

    /**
     * @brief updatePrefOnDisk
     * @return
     */
    bool updatePrefOnDisk(void);
signals:

public slots:
private:
    QFile current_pref_file;
    QHash<QString,QString> pref_map;
};

#endif // PREFERENCEHANDLER_H
