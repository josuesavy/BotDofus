#ifndef PRESETUSERESULTWITHMISSINGIDSMESSAGE_H
#define PRESETUSERESULTWITHMISSINGIDSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/presets/PresetUseResultMessage.h"

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