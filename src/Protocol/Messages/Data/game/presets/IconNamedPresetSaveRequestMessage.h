#ifndef ICONNAMEDPRESETSAVEREQUESTMESSAGE_H
#define ICONNAMEDPRESETSAVEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/presets/IconPresetSaveRequestMessage.h"

class IconNamedPresetSaveRequestMessage : public IconPresetSaveRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IconNamedPresetSaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IconNamedPresetSaveRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IconNamedPresetSaveRequestMessage(FuncTree tree);
  IconNamedPresetSaveRequestMessage();

  QString name;
  uint type;

private:
  void _nameFunc(Reader *input);
  void _typeFunc(Reader *input);
};

#endif // ICONNAMEDPRESETSAVEREQUESTMESSAGE_H