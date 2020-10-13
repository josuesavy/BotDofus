#ifndef IDOLSPRESETSAVEREQUESTMESSAGE_H
#define IDOLSPRESETSAVEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/presets/IconPresetSaveRequestMessage.h"

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