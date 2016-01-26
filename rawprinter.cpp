#include "rawprinter.h"

RawPrinter::RawPrinter(QObject *parent) : QObject(parent)
{
    opened = false;
}

RawPrinter::RawPrinter(QString printer_name, QObject *parent) : RawPrinter(parent)
{
    open(printer_name);
}

RawPrinter::~RawPrinter()
{
    if (opened) {
        ClosePrinter(hPrinter);
    }
}

int RawPrinter::open(QString printer_name)
{
    int ret = OpenPrinter((LPWSTR)printer_name.toStdWString().c_str(), &hPrinter, NULL);
    if (ret) {
        opened = true;
    } else {
        QTextStream(stdout) << "Error: " << GetLastError() << "\n";
    }
    return ret;
}

void RawPrinter::close()
{
    if (opened) {
        ClosePrinter(hPrinter);
        opened = false;
    }
}

int RawPrinter::print(QString text)
{
    if (!opened) return 1;

    unsigned long len;
    QByteArray bytes = text.toLatin1();
    const char *buf = bytes.data();

    DOC_INFO_1 info;

    info.pDocName = L"Document";
    info.pOutputFile = NULL;
    info.pDatatype = L"RAW";

    StartDocPrinter(hPrinter, 1, (LPBYTE)&info);
    StartPagePrinter(hPrinter);
    int ret = WritePrinter(hPrinter, (LPVOID*)buf, strlen(buf), &len);
    EndPagePrinter(hPrinter);
    EndDocPrinter(hPrinter);
    if(ret) QTextStream(stdout) << "Error: " << GetLastError() << "\n";
    return ret;
}
