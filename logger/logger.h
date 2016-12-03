#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class logger : public QObject
{
    Q_OBJECT
public:
    explicit logger(QObject *parent = 0);

signals:

public slots:
    /**
     * @brief log: writes log string on screen and on log file
     * @param origin: file or tag to identify the log string
     * @param string: data to be written
     */
    void log(QString origin, QString string);
private:
    QFile logFile;
    QTextStream filestream;
};

#endif // LOGGER_H
