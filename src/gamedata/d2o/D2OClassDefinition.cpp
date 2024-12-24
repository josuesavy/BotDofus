#include "D2OClassDefinition.h"
#include "src/protocol/datacenter/GameDataConverter.h"

D2OClassDefinition::D2OClassDefinition(const QString &className):
    m_className(className)
{
}

void D2OClassDefinition::addD2OField(const QString &D2OFieldName, Reader *reader)
{
    m_D2OFields<<new D2OField(D2OFieldName, reader);
}

D2OClassDefinition::~D2OClassDefinition()
{
    foreach(D2OField *D2OField, m_D2OFields)
        delete D2OField;
}

void D2OClassDefinition::setD2OField(QMap<int, D2OClassDefinition*> &classes, I18nFile *I18n)
{
    for (int i = 0; i < m_D2OFields.size(); i++)
        m_D2OFields[i]->setClasses(classes, I18n);
}

QSharedPointer<AbstractGameData> D2OClassDefinition::read(Reader *reader, I18nFile *I18n)
{
    foreach (D2OField *D2OField, m_D2OFields)
        D2OField->read(reader);

    QSharedPointer<AbstractGameData> gameData = GameDataConverter::getClass(m_className);

    if(gameData != NULL)
        gameData->loadData(m_D2OFields, I18n);

    return gameData;
}
