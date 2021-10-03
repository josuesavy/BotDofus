#ifndef PRESETSCONTAINERPRESET_H
#define PRESETSCONTAINERPRESET_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/presets/Preset.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PresetsContainerPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetsContainerPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetsContainerPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetsContainerPreset(FuncTree tree);
  PresetsContainerPreset();
  bool operator==(const PresetsContainerPreset &compared);

  QList<QSharedPointer<Preset>> presets;

private:
  void _presetstreeFunc(Reader *input);
  void _presetsFunc(Reader *input);

  FuncTree _presetstree;
};

#endif // PRESETSCONTAINERPRESET_H