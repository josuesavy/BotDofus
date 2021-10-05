#include "BasicElement.h"
#include "SoundElement.h"
#include "GraphicalElement.h"

BasicElement::BasicElement(Reader *reader, Map *map, int cellId)
{
    uchar be = reader->readByte();

    switch ((ElementTypesEnum)be)
    {
    case ElementTypesEnum::GRAPHICAL:
    {
        m_element = QSharedPointer<BasicElement>(new GraphicalElement(reader, map, cellId));
    }
        break;

    case ElementTypesEnum::SOUND:
    {
        m_element = QSharedPointer<BasicElement>(new SoundElement(reader));
    }
        break;

    default:
        break;
    }
}

QSharedPointer<BasicElement> BasicElement::getElement()
{
    return m_element;
}
