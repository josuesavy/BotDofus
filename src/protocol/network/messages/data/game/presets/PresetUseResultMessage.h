#ifndef PRESETUSERESULTMESSAGE_H
#define PRESETUSERESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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