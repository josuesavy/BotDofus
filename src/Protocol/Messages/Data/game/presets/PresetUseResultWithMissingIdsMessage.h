#ifndef PRESETUSERESULTWITHMISSINGIDSMESSAGE_H
#define PRESETUSERESULTWITHMISSINGIDSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/presets/PresetUseResultMessage.h"

class PresetUseResultWithMissingIdsMessage : public PresetUseResultMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetUseResultWithMissingIdsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetUseResultWithMissingIdsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetUseResultWithMissingIdsMessage(FuncTree tree);
  PresetUseResultWithMissingIdsMessage();

  QList<uint> missingIds;

private:
  void _missingIdstreeFunc(Reader *input);
  void _missingIdsFunc(Reader *input);

  FuncTree _missingIdstree;
};

#endif // PRESETUSERESULTWITHMISSINGIDSMESSAGE_H