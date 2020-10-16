#ifndef PRESETSCONTAINERPRESET_H
#define PRESETSCONTAINERPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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