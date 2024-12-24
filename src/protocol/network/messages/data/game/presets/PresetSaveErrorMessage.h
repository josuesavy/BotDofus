#ifndef PRESETSAVEERRORMESSAGE_H
#define PRESETSAVEERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PresetSaveErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PresetSaveErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PresetSaveErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PresetSaveErrorMessage(FuncTree tree);
  PresetSaveErrorMessage();

  int presetId;
  uint code;

private:
  void _presetIdFunc(Reader *input);
  void _codeFunc(Reader *input);
};

#endif // PRESETSAVEERRORMESSAGE_H