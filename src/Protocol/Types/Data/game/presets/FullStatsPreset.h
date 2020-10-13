#ifndef FULLSTATSPRESET_H
#define FULLSTATSPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/CharacterCharacteristicForPreset.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FullStatsPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FullStatsPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FullStatsPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FullStatsPreset(FuncTree tree);
  FullStatsPreset();
  bool operator==(const FullStatsPreset &compared);

  QList<CharacterCharacteristicForPreset> stats;

private:
  void _statstreeFunc(Reader *input);
  void _statsFunc(Reader *input);

  FuncTree _statstree;
};

#endif // FULLSTATSPRESET_H