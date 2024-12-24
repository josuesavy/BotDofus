#include "gui/windows/mainwindow.h"
#include "gui/windows/dialogs/connectiondialog.h"
#include "gui/utils/theme.h"

#include <QApplication>
#include <QMutex>

//some constants to parameterize.
const qint64 LOG_FILE_LIMIT = 3000000;
const QString LOG_PATH = "./logs/";
const QString LOG_FILENAME = "botdofus";
const QString LOG_EXTENSION = ".log";

//thread safety
QMutex mutex;

// Global variable to track the current log file
QString currentLogFile;

void initializeLogFile()
{
    QDir logDir(LOG_PATH);
    if (!logDir.exists()) {
        logDir.mkpath(".");
    }

    // Find the latest log file index
    int logIndex = 0;
    // while (QFile::exists(LOG_PATH + LOG_FILENAME + "." + QString::number(logIndex) + LOG_EXTENSION)) {
    //     logIndex++;
    // }

    // Create a new log file
    currentLogFile = LOG_PATH + LOG_FILENAME + "." + QString::number(logIndex) + LOG_EXTENSION;
    // QFile newLogFile(currentLogFile);
    // newLogFile.open(QIODevice::WriteOnly); // Create an empty file
    // newLogFile.close();
}

void redirectDebugMessages(QtMsgType type, const QMessageLogContext & context, const QString & str)
{
    //thread safety
    mutex.lock();
    QString txt;

    //prepend timestamp to every message
    QString datetime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss:zzz");
    //prepend a log level label to every message
    switch (type) {
    case QtDebugMsg:
        txt = QString(" [Debug] ");
        break;
    case QtWarningMsg:
        txt = QString(" [Warning] ");
        break;
    case QtInfoMsg:
        txt = QString(" [Info] ");
        break;
    case QtCriticalMsg:
        txt = QString(" [Fatal] ");
        break;
    }

    // Check if the current file exceeds the limit
    if (QFile(currentLogFile).size() >= LOG_FILE_LIMIT) {
        // Create a new log file with the next index
        QString baseFileName = LOG_PATH + LOG_FILENAME;
        int currentIndex = currentLogFile.section('.', -2, -2).toInt();
        currentLogFile = baseFileName + "." + QString::number(currentIndex + 1) + LOG_EXTENSION;

        QFile newLogFile(currentLogFile);
        newLogFile.open(QIODevice::WriteOnly); // Create an empty file
        newLogFile.close();
    }

    // Write the message to the current log file
    QFile outFile(currentLogFile);
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << datetime << txt << str << endl;

    //close fd
    outFile.close();
    mutex.unlock();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Initialize the log file at program start
    initializeLogFile();

    // Redirect debug messages
    qInstallMessageHandler(redirectDebugMessages);

    // Chargement du thème
    qApp->setStyle(Theme::style());
    //qApp->setFont(Theme::font(QApplication::font()));
    qApp->setPalette(Theme::palette());
    qApp->setStyleSheet(Theme::styleSheet());

    ConnectionDialog cd;
    cd.show();

    return a.exec();
}
