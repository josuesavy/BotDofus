#pragma once

#include <QDebug>

#include "src/engines/io/ele/GraphicalElementData.h"
#include "src/engines/io/ele/GraphicalElementTypes.h"
#include "src/engines/io/ele/subtypes/AnimatedGraphicalElementData.h"
#include "src/engines/io/ele/subtypes/BlendedGraphicalElementData.h"
#include "src/engines/io/ele/subtypes/BoundingBoxGraphicalElementData.h"
#include "src/engines/io/ele/subtypes/EntityGraphicalElementData.h"
#include "src/engines/io/ele/subtypes/NormalGraphicalElementData.h"
#include "src/engines/io/ele/subtypes/ParticlesGraphicalElementData.h"

class GraphicalElementFactory
{
public:
    GraphicalElementFactory();

    static QSharedPointer<GraphicalElementData> getGraphicalElementData(int elementId, int elementType);
};
