#ifndef PRESETDELETEREQUESTMESSAGE_H
#define PRESETDELETEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PresetDeleteRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetDeleteRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetDeleteRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetDeleteRequestMessage(FuncTree tree);
  PresetDeleteRequestMessage();

  int presetId;

private:
  void _presetIdFunc(Reader *input);
};

#endif // PRESETDELETEREQUESTMESSAGE_H