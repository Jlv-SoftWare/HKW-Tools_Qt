#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>

namespace Qt
{
    static QMutex mutex;

    static void CustomMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
    {
        //Q_UNUSED(context)
        QDateTime _datetime = QDateTime::currentDateTime();
        QString szDate = _datetime.toString("yyyy-MM-dd hh:mm:ss.zzz");//"yyyy-MM-dd hh:mm:ss ddd"
        QString txt(szDate);

        switch (type)
        {
        case QtDebugMsg://调试信息提示
        {
            txt += QString(" [Debug] ");
            break;
        }
        case QtInfoMsg://信息输出
        {
            txt += QString(" [Info] ");
            break;
        }
        case QtWarningMsg://一般的warning提示
        {
            txt += QString(" [Warning] ");
            break;
        }
        case QtCriticalMsg://严重错误提示
        {
            txt += QString(" [Critical] ");
            break;
        }
        case QtFatalMsg://致命错误提示
        {
            txt += QString(" [Fatal] ");
            //abort();
            break;
        }
        default:
        {
            txt += QString(" [Trace] ");
            break;
        }
        }

        txt.append(QString(" %1").arg(context.file));
        txt.append(QString("<%1>: ").arg(context.line));
        txt.append(msg);

        Qt::mutex.lock();
        
        QFile file(QDir::cleanPath(QCoreApplication::applicationDirPath() + QDir::separator() + "log.txt"));
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream text_stream(&file);
        text_stream << txt << "\r\n";
        file.close();
        Qt::mutex.unlock();
    }
}

