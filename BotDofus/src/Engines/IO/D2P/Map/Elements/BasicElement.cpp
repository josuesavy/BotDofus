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
        m_element = new GraphicalElement(reader, map, cellId);
    }
        break;

    case ElementTypesEnum::SOUND:
    {
        m_element = new SoundElement(reader);
    }
        break;

    default:
        break;
    }
}

BasicElement *BasicElement::getElement()
{
    return m_element;
}
