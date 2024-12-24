#ifndef STATSPRESET_H
#define STATSPRESET_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/presets/SimpleCharacterCharacteristicForPreset.h"
#include "src/protocol/network/types/data/game/presets/Preset.h"
#include "src/utils/io/type/FuncTree.h"

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