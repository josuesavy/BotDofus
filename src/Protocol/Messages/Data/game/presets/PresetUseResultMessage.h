#ifndef PRESETUSERESULTMESSAGE_H
#define PRESETUSERESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PresetUseResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetUseResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetUseResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetUseResultMessage(FuncTree tree);
  PresetUseResultMessage();

  int presetId;
  uint code;

private:
  void _presetIdFunc(Reader *input);
  void _codeFunc(Reader *input);
};

#endif // PRESETUSERESULTMESSAGE_H