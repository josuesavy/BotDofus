#ifndef WRAPPEROBJECTERRORMESSAGE_H
#define WRAPPEROBJECTERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/SymbioticObjectErrorMessage.h"

class WrapperObjectErrorMessage : public SymbioticObjectErrorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WrapperObjectErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WrapperObjectErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WrapperObjectErrorMessage(FuncTree tree);
  WrapperObjectErrorMessage();
};

#endif // WRAPPEROBJECTERRORMESSAGE_H