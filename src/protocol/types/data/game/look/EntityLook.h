#ifndef ENTITYLOOK_H
#define ENTITYLOOK_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/look/SubEntity.h"
#include "src/engines/io/network/utils/FuncTree.h"

class EntityLook : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntityLook(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntityLook(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntityLook(FuncTree tree);
  EntityLook();
  bool operator==(const EntityLook &compared);

  uint bonesId;
  QList<uint> skins;
  QList<int> indexedColors;
  QList<int> scales;
  QList<QSharedPointer<SubEntity>> subentities;

private:
  void _bonesIdFunc(Reader *input);
  void _skinstreeFunc(Reader *input);
  void _skinsFunc(Reader *input);
  void _indexedColorstreeFunc(Reader *input);
  void _indexedColorsFunc(Reader *input);
  void _scalestreeFunc(Reader *input);
  void _scalesFunc(Reader *input);
  void _subentitiestreeFunc(Reader *input);
  void _subentitiesFunc(Reader *input);

  FuncTree _skinstree;
  FuncTree _indexedColorstree;
  FuncTree _scalestree;
  FuncTree _subentitiestree;
};

#endif // ENTITYLOOK_H