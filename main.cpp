#include <QCoreApplication>
#include <QList>
#include <QStringList>
#include <iostream>
#include <sstream>
#include "texttable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QStringList > table;
    QStringList header;
    header <<"DLL"<<"Require Version"<<"Actual Version"<<"Compatible";
    table.append(header);

    QStringList detectorDll;
    detectorDll<<"XrfDetectByInet.dll"<<"2.5.0"<<"2.10.1"<<"OK";
    table.append(detectorDll);

    QStringList zmqDll;
    zmqDll<<"zmq.dll"<<"4.0.0"<<"4.0.3"<<"OK";
    table.append(zmqDll);

    QStringList modbusDll;
    modbusDll<<"modbus.dll"<<"3.0.0"<<"3.1.3"<<"Failed";
    table.append(modbusDll);

    TextTable *textTable = new TextTable(table);
/*
    std::ostringstream local;
    std::streambuf* cout_buff = std::cout.rdbuf(); // save pointer to std::cout buffer
    std::cout.rdbuf(local.rdbuf()); // substitute internal std::cout buffer with
*/
    textTable->draw();
/*
    std::cout.rdbuf(cout_buff);
    QString versionTable = QString("%1").arg(local.str().c_str());
    std::cout << qPrintable(versionTable);
*/
    return a.exec();
}
