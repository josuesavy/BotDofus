#ifndef PRESETDELETEREQUESTMESSAGE_H
#define PRESETDELETEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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