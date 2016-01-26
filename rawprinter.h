#ifndef RAWPRINTER_H
#define RAWPRINTER_H

#include <QObject>
#include <QTextStream>
#include <windows.h>
#include <winspool.h>


class RawPrinter : public QObject
{
    Q_OBJECT
public:
    RawPrinter(QObject *parent = 0);
    RawPrinter(QString printer_name, QObject *parent = 0);
    ~RawPrinter();
    Q_INVOKABLE int open(QString printer_name);
    Q_INVOKABLE void close();
    Q_INVOKABLE int print(QString text);

signals:
public slots:

private:
    HANDLE hPrinter;
    bool opened;
};

#endif // RAWPRINTER_H
