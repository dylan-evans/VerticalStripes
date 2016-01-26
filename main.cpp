#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTextStream>
#include <QPrinter>
#include <QPrinterInfo>
#include <QtQml>

#include <windows.h>
#include <winspool.h>

#include "rawprinter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    RawPrinter zebra("Labels");
    //const char str[] = "^XA^LH 80,80\n^FO20,10^ADN,200,40^FDWikipedia^FS\n^LH0,0\n^XZ";
    const char str[] = "^XA^LH 80,80\n^BCN,100^FD12345678^FS\n^LH0,0\n^XZ";

//    zebra.print(QString(str));

    qmlRegisterType<RawPrinter>("RawPrinter", 1, 0, "RawPrinter");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
