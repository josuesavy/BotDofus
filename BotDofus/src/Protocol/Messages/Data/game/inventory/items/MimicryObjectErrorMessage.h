#ifndef MIMICRYOBJECTERRORMESSAGE_H
#define MIMICRYOBJECTERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/SymbioticObjectErrorMessage.h"

class MimicryObjectErrorMessage : public SymbioticObjectErrorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MimicryObjectErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MimicryObjectErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MimicryObjectErrorMessage(FuncTree tree);
  MimicryObjectErrorMessage();

  bool preview;

private:
  void _previewFunc(Reader *input);
};

#endif // MIMICRYOBJECTERRORMESSAGE_H