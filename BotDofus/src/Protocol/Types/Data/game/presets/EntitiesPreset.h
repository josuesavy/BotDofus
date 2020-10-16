#ifndef ENTITIESPRESET_H
#define ENTITIESPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class EntitiesPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntitiesPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntitiesPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntitiesPreset(FuncTree tree);
  EntitiesPreset();
  bool operator==(const EntitiesPreset &compared);

  uint iconId;
  QList<uint> entityIds;

private:
  void _iconIdFunc(Reader *input);
  void _entityIdstreeFunc(Reader *input);
  void _entityIdsFunc(Reader *input);

  FuncTree _entityIdstree;
};

#endif // ENTITIESPRESET_H