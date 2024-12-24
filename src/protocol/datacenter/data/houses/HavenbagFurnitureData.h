#ifndef HAVENBAGFURNITUREDATA_H
#define HAVENBAGFURNITUREDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class HavenbagFurnitureData : public AbstractGameData
{
public:
  int getTypeId() const;
  int getThemeId() const;
  int getElementId() const;
  int getColor() const;
  int getLayerId() const;
  bool getBlocksMovement() const;
  bool getIsStackable() const;
  uint getCellsWidth() const;
  uint getCellsHeight() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_typeId;
  int m_themeId;
  int m_elementId;
  int m_color;
  int m_layerId;
  bool m_blocksMovement;
  bool m_isStackable;
  uint m_cellsWidth;
  uint m_cellsHeight;
};

#endif // HAVENBAGFURNITUREDATA_H