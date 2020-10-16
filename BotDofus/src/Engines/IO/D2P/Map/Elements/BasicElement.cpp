#include "BasicElement.h"

BasicElement::BasicElement(Reader *reader, Map *map, int cellId)
{
    uchar be = reader->readByte();

    switch ((ElementTypesEnum)be)
    {
    case ElementTypesEnum::GRAPHICAL: {
        GraphicalElement ge(reader, map, cellId); }
        break;

    case ElementTypesEnum::SOUND: {
        SoundElement se(reader); }
        break;

    default:
        break;
    }
}
