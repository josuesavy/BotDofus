#ifndef PRESETSAVEERRORMESSAGE_H
#define PRESETSAVEERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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