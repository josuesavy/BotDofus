#ifndef STATSPRESET_H
#define STATSPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/SimpleCharacterCharacteristicForPreset.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class StatsPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatsPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatsPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatsPreset(FuncTree tree);
  StatsPreset();
  bool operator==(const StatsPreset &compared);

  QList<SimpleCharacterCharacteristicForPreset> stats;

private:
  void _statstreeFunc(Reader *input);
  void _statsFunc(Reader *input);

  FuncTree _statstree;
};

#endif // STATSPRESET_H