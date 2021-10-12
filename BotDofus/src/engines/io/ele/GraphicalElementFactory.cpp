#include "GraphicalElementFactory.h"

GraphicalElementFactory::GraphicalElementFactory()
{

}

QSharedPointer<GraphicalElementData> GraphicalElementFactory::getGraphicalElementData(int elementId, int elementType)
{
    switch ((GraphicalElementTypes)elementType)
    {
    case GraphicalElementTypes::NORMAL:
        return new NormalGraphicalElementData(elementId, elementType);
        break;
    case GraphicalElementTypes::BOUNDING_BOX:
        return new BoundingBoxGraphicalElementData(elementId, elementType);
        break;
    case GraphicalElementTypes::ANIMATED:
        return new AnimatedGraphicalElementData(elementId, elementType);
        break;
    case GraphicalElementTypes::ENTITY:
        return new EntityGraphicalElementData(elementId, elementType);
        break;
    case GraphicalElementTypes::PARTICLES:
        return new ParticlesGraphicalElementData(elementId, elementType);
        break;
    case GraphicalElementTypes::BLENDED:
        return new BlendedGraphicalElementData(elementId, elementType);
        break;
    default:
        qDebug() << "Unknown graphical element data type " << elementType << " for element " << elementId << "!";
        return NULL;
        break;
    }
}
