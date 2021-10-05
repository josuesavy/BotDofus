#ifndef IDOLSPRESETSAVEREQUESTMESSAGE_H
#define IDOLSPRESETSAVEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/presets/IconPresetSaveRequestMessage.h"

class IdolsPresetSaveRequestMessage : public IconPresetSaveRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolsPresetSaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolsPresetSaveRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolsPresetSaveRequestMessage(FuncTree tree);
  IdolsPresetSaveRequestMessage();
};

#endif // IDOLSPRESETSAVEREQUESTMESSAGE_H