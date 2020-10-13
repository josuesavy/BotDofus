#ifndef PRESETDELETERESULTMESSAGE_H
#define PRESETDELETERESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PresetDeleteResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetDeleteResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetDeleteResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetDeleteResultMessage(FuncTree tree);
  PresetDeleteResultMessage();

  int presetId;
  uint code;

private:
  void _presetIdFunc(Reader *input);
  void _codeFunc(Reader *input);
};

#endif // PRESETDELETERESULTMESSAGE_H