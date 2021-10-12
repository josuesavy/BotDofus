#include "GraphicalElementFactory.h"

GraphicalElementFactory::GraphicalElementFactory()
{

}

QSharedPointer<GraphicalElementData> GraphicalElementFactory::getGraphicalElementData(int elementId, int elementType)
{
    switch ((GraphicalElementTypes)elementType)
    {
    case GraphicalElementTypes::NORMAL:
        return QSharedPointer<GraphicalElementData>(new NormalGraphicalElementData(elementId, elementType));
        break;
    case GraphicalElementTypes::BOUNDING_BOX:
        return QSharedPointer<GraphicalElementData>(new BoundingBoxGraphicalElementData(elementId, elementType));
        break;
    case GraphicalElementTypes::ANIMATED:
        return QSharedPointer<GraphicalElementData>(new AnimatedGraphicalElementData(elementId, elementType));
        break;
    case GraphicalElementTypes::ENTITY:
        return QSharedPointer<GraphicalElementData>(new EntityGraphicalElementData(elementId, elementType));
        break;
    case GraphicalElementTypes::PARTICLES:
        return QSharedPointer<GraphicalElementData>(new ParticlesGraphicalElementData(elementId, elementType));
        break;
    case GraphicalElementTypes::BLENDED:
        return QSharedPointer<GraphicalElementData>(new BlendedGraphicalElementData(elementId, elementType));
        break;
    default:
        qDebug() << "Unknown graphical element data type " << elementType << " for element " << elementId << "!";
        return NULL;
        break;
    }
}
