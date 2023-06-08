#include "mainwindow.h"
#include "casetable.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QApplication>
#include <windows.h>

QScopedPointer<QFile> logFile;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream out(logFile.data());
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    switch (type)
    {
    case QtInfoMsg:     out << "INF "; break;
    case QtDebugMsg:    out << "DBG "; break;
    case QtWarningMsg:  out << "WRN "; break;
    case QtCriticalMsg: out << "CRT "; break;
    case QtFatalMsg:    out << "FTL "; break;
    }
    out << context.category << ": "
        << msg << endl;
    out.flush();
}

int main(int argc, char *argv[])
{
//    CaseTable table;
//    table.fillTableFromFile("D:/C++/cases.txt");
//    std::pair<std::string, std::string> res;
//    res = table.checkWord("тигру");
//    std::cout << "jnjn";
    setlocale(LC_ALL, "Russian");

    QApplication a(argc, argv);

    logFile.reset(new QFile("D:/C++/WordsAndCases/log.txt"));
    logFile.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);

    MainWindow w;
    w.show();

    return a.exec();

//    return 1;
}
