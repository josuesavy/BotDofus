#ifndef ICONPRESETSAVEREQUESTMESSAGE_H
#define ICONPRESETSAVEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class IconPresetSaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IconPresetSaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IconPresetSaveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IconPresetSaveRequestMessage(FuncTree tree);
  IconPresetSaveRequestMessage();

  int presetId;
  uint symbolId;
  bool updateData;

private:
  void _presetIdFunc(Reader *input);
  void _symbolIdFunc(Reader *input);
  void _updateDataFunc(Reader *input);
};

#endif // ICONPRESETSAVEREQUESTMESSAGE_H