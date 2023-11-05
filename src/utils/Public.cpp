#include "Public.h"

#include "string"
#include <iostream>
#include <math.h>
#include <stdint.h>
#include <sstream>
#include <limits>
#include <cassert>

QByteArray gUncompress(const QByteArray &data)
{
    if (data.size() <= 4)
    {
        qWarning("gUncompress: Input data is truncated");
        return QByteArray();
    }

    QByteArray result;

    int ret;
    z_stream strm;
    static const int CHUNK_SIZE = 1024;
    char out[CHUNK_SIZE];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = data.size();
    strm.next_in = (Bytef*)(data.data());

    ret = inflateInit2(&strm, 15 +  32);
    if (ret != Z_OK)
        return QByteArray();

    do {
        strm.avail_out = CHUNK_SIZE;
        strm.next_out = (Bytef*)(out);

        ret = inflate(&strm, Z_NO_FLUSH);
        Q_ASSERT(ret != Z_STREAM_ERROR);

        switch (ret) {
        case Z_NEED_DICT:
            ret = Z_DATA_ERROR;
        case Z_DATA_ERROR:
        case Z_MEM_ERROR:
            (void)inflateEnd(&strm);
            return QByteArray();
        }

        result.append(out, CHUNK_SIZE - strm.avail_out);
    } while (strm.avail_out == 0);

    inflateEnd(&strm);
    return result;
}

//Convertisseurs chiffres/lettres
int toInt(QString string)
{
    std::string stdString = string.toStdString();
    std::istringstream number (stdString);
    int result;

    number >> result;

    return result;
}

uint toUInt(QString string)
{
    std::string stdString = string.toStdString();
    std::istringstream number (stdString);
    uint result;

    number >> result;

    return result;
}

float toFloat(QString string)
{
    std::string stdString = string.toStdString();
    std::istringstream number (stdString);
    float result;

    number >> result;

    return result;
}

QString dateToString(const double &milliseconds)
{
    uint seconds = milliseconds/1000;

    QDateTime toDateTime = QDateTime::fromTime_t(seconds);

    QString dateToString;
    dateToString = toDateTime.toString("dd/MM/yyyy hh:mm:ss");

    return dateToString;
}

QString millisecondsToHHMMSS(uint milliseconds)
{
    int sec_num = milliseconds / 1000;
    int secsUsed = 0;

    int years = qFloor(sec_num / 31536000);
    if (years > 0)
        secsUsed += (years * 31536000);

    int months = qFloor((sec_num - secsUsed) / 2628288);
    if (months > 0)
        secsUsed += (months * 2628288);

    int weeks = qFloor((sec_num - secsUsed) / 604800);
    if (weeks > 0)
        secsUsed += (weeks * 604800);

    int days = qFloor((sec_num - secsUsed) / 86400);
    if (days > 0)
        secsUsed += (days * 86400);

    int hours = qFloor((sec_num - secsUsed) / 3600);
    if (hours > 0)
        secsUsed += (hours * 3600);

    int minutes = qFloor((sec_num - secsUsed) / 60);
    if (minutes > 0)
        secsUsed += (minutes * 60);

    int seconds = sec_num - secsUsed;

    if (years > 0)
        return QString("%1y %2mths %3wks %4d %5h %6min %7s").arg(years).arg(months).arg(weeks).arg(days).arg(hours).arg(minutes).arg(seconds);

    else if (months > 0)
        return QString("%1mths %2wks %3d %4h %5min %6s").arg(months).arg(weeks).arg(days).arg(hours).arg(minutes).arg(seconds);

    else if (weeks > 0)
        return QString("%1wks %2d %3h %4min %5s").arg(weeks).arg(days).arg(hours).arg(minutes).arg(seconds);

    else if (days > 0)
        return QString("%1d %2h %3min %4s").arg(days).arg(hours).arg(minutes).arg(seconds);

    else if (hours > 0)
        return QString("%1h %2min %3s").arg(hours).arg(minutes).arg(seconds);

    else if (minutes > 0)
        return QString("%1min %2s").arg(minutes).arg(seconds);

    else if (seconds > 0)
        return QString("%1s").arg(seconds);

    else if (seconds == 0)
        return QString("%1ms").arg(milliseconds);

    else
        return QString("%1d %2h %3min %4s").arg(days).arg(hours).arg(minutes).arg(seconds);
}

QString getRessourcesPath()
{
    QString path = QCoreApplication::applicationDirPath();

#ifdef __APPLE__
    path.remove(path.size()-6, 7);
    path+="/Resources";
#endif

    return path;
}

QString toHtml(const QString &plainText)
{
    QString htmlText;
    int charactersAdded= 0;

    for(int i = 0; i < plainText.size(); i++)
    {
        if (plainText[i] == '\n')
        {
            htmlText.insert(i+charactersAdded, "<br/>");
            charactersAdded += 4;
        }

        else if (plainText[i] == '\t')
            htmlText.insert(i+charactersAdded, "    ");

        else
            htmlText+=plainText[i];
    }

    return htmlText;
}
