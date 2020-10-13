#include "I18nFile.h"


I18nFile::I18nFile(const QString &path)
{
    m_accessor = new I18nFileAccessor(path);
}

I18nFile::~I18nFile()
{
    delete m_accessor;
}

QString I18nFile::getText(int id)
{
    if (!m_accessor->indexExist(id))
        qDebug()<<"ERROR - I18nFile - Index"<<id<<"was not found !";

    return m_accessor->getText(id);
}

QString I18nFile::getText(const QString &id)
{
    if (!m_accessor->indexExist(id))
        qDebug()<<"ERROR - I18nFile - Index"<<id<<"was not found !";

    return m_accessor->getText(id);
}

