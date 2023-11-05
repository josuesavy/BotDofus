#pragma once

#include "WorldPoint.h"
#include "src/utils/io/Reader.h"
#include "CellData.h"
#include "src/gamedata/d2p/CompressedMap.h"
#include "Fixture.h"
#include "Layer.h"
#include "src/utils/Public.h"

class Layer;

class Map
{
    friend class CellData;
    friend class GraphicalElement;

public:
    Map();
    Map(CompressedMap *compressedMap);

    bool isInit() const;

    uint getMapId() const;
    int getRightMapId() const;
    int getLeftMapId() const;
    int getTopMapId() const;
    int getBottomMapId() const;
    int getSubAreaId() const;
    QList<CellData> getCellData() const;
    QList<Fixture> getBackgroundFixtures() const;
    QList<Fixture> getForegroundFixtures() const;
    QList<Layer> getLayers() const;
    WorldPoint getPosition() const;
    int getMapVersion() const;
    int getInteractiveElementCellID(int elementId) const;
    QList<uint> getFixedMapChanger() const;
    QList<uint> getTopArrowCells() const;
    QList<uint> getBottomArrowCells() const;
    QList<uint> getRightArrowCells() const;
    QList<uint> getLeftArrowCells() const;

private:
    void initializeMap(CompressedMap *compressedMap);
    void addTopArrowCell(uint cellId);
    void addBottomArrowCell(uint cellId);
    void addLeftArrowCell(uint cellId);
    void addRightArrowCell(uint cellId);

    bool m_isInit;

    uint m_mapId;
    int m_rightMapId;
    int m_leftMapId;
    int m_topMapId;
    int m_bottomMapId;
    int m_subAreaId;
    int m_mapVersion;
    WorldPoint m_position;
    QList<CellData> m_cellData;
    QList<Fixture> m_backgroundFixtures;
    QList<Fixture> m_foregroundFixtures;
    QList<Layer> m_layers;
    QMap<int, int> m_interactiveElements;
    QList<uint> m_fixedMapChangers;
    static QByteArray m_encryptionKey;
    QList<uint> m_topArrowCells;
    QList<uint> m_bottomArrowCells;
    QList<uint> m_leftArrowCells;
    QList<uint> m_rightArrowCells;

};

