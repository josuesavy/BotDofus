#ifndef IDOLSPRESET_H
#define IDOLSPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class IdolsPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolsPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolsPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolsPreset(FuncTree tree);
  IdolsPreset();
  bool operator==(const IdolsPreset &compared);

  uint iconId;
  QList<uint> idolIds;

private:
  void _iconIdFunc(Reader *input);
  void _idolIdstreeFunc(Reader *input);
  void _idolIdsFunc(Reader *input);

  FuncTree _idolIdstree;
};

#endif // IDOLSPRESET_H