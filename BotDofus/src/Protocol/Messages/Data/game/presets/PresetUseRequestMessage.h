#ifndef PRESETUSEREQUESTMESSAGE_H
#define PRESETUSEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PresetUseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetUseRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetUseRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetUseRequestMessage(FuncTree tree);
  PresetUseRequestMessage();

  int presetId;

private:
  void _presetIdFunc(Reader *input);
};

#endif // PRESETUSEREQUESTMESSAGE_H