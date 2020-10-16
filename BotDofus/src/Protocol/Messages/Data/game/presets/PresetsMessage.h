#ifndef PRESETSMESSAGE_H
#define PRESETSMESSAGE_H

#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PresetsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetsMessage(FuncTree tree);
  PresetsMessage();

  QList<QSharedPointer<Preset>> presets;

private:
  void _presetstreeFunc(Reader *input);
  void _presetsFunc(Reader *input);

  FuncTree _presetstree;
};

#endif // PRESETSMESSAGE_H