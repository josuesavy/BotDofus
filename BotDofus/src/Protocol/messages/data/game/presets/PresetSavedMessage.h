#ifndef PRESETSAVEDMESSAGE_H
#define PRESETSAVEDMESSAGE_H

#include "src/protocol/types/data/game/presets/Preset.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class PresetSavedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetSavedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetSavedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetSavedMessage(FuncTree tree);
  PresetSavedMessage();

  int presetId;
  QSharedPointer<Preset> preset;

private:
  void _presetIdFunc(Reader *input);
  void _presettreeFunc(Reader *input);

  FuncTree _presettree;
};

#endif // PRESETSAVEDMESSAGE_H