#ifndef PRESETSAVEDMESSAGE_H
#define PRESETSAVEDMESSAGE_H

#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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