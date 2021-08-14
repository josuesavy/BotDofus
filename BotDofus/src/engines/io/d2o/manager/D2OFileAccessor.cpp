#include "D2OFileAccessor.h"


D2OFileAccessor::D2OFileAccessor(const QString &path, I18nFile *I18n):
    m_path(path),
    m_I18n(I18n)
{
    m_reader = new Reader(m_path);

    uint contentOffset = 0;
    QString header = m_reader->readBytes(3).data();

    if (header != "D2O")
    {
        m_reader->setPosition(0);
        header = m_reader->readUTF();

        if (header != "AKSF")
            qDebug()<<"ERROR - D2OFileAccessor - D2O file is malformed (AKSF)"<<path;

        m_reader->readShort();
        uint len = m_reader->readInt();
        m_reader->setPosition(m_reader->getPosition() + len);
        contentOffset = m_reader->getPosition();
        // TODO: line missing
        header = m_reader->readBytes(3).data();

        if (header != "D2O")
            qDebug()<<"ERROR - D2OFileAccessor - D2O file is malformed (D2O)"<<path;
    }

    int indexPos = m_reader->readInt();
    m_reader->setPosition(indexPos + contentOffset);

    int indexCount = m_reader->readInt();
    for (int i = 1; i < indexCount; i += 8)
    {
        int index = m_reader->readInt();
        int pos = m_reader->readInt();
        m_indexes[index] = pos + contentOffset;
    }

    int classesCount = m_reader->readInt();
    for (int i = 0; i < classesCount; i++)
    {
        int classId = m_reader->readInt();
        m_classes[classId] = readD2OClassDefinition();
    }

    foreach(D2OClassDefinition *classDef, m_classes)
        classDef->setD2OField(m_classes, m_I18n);
}

D2OFileAccessor::~D2OFileAccessor()
{
    delete m_reader;

    foreach(D2OClassDefinition *def, m_classes.values())
        delete def;
}

D2OClassDefinition *D2OFileAccessor::readD2OClassDefinition()
{
    QString className = m_reader->readUTF();
    QString classNamespace = m_reader->readUTF();
    D2OClassDefinition *m_class = new D2OClassDefinition(className);

    int D2OFieldCount = m_reader->readInt();
    for (int i = 0; i < D2OFieldCount; i++)
    {
        QString D2OFieldName = m_reader->readUTF();
        m_class->addD2OField(D2OFieldName, m_reader);
    }

    return m_class;
}

QSharedPointer<AbstractGameData> D2OFileAccessor::read(int index)
{
    if (!m_indexes.contains(index))
        qDebug()<<"ERROR - D2OFileAccessor didn't find the index:"<<index;

    m_reader->setPosition(m_indexes[index]);
    int classId = m_reader->readInt();
    return m_classes[classId]->read(m_reader, m_I18n);
}


QList<int> D2OFileAccessor::getIndexes()
{
    return m_indexes.keys();
}
