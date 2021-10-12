#pragma once

#include <QDebug>

#include "src/engines/io/ele/GraphicalElementData.h"
#include "src/engines/io/ele/GraphicalElementTypes.h"

class GraphicalElementFactory
{
public:
    GraphicalElementFactory();

    static QSharedPointer<GraphicalElementData> getGraphicalElementData(int elementId, int elementType);
};
