#ifndef WRAPPEROBJECTERRORMESSAGE_H
#define WRAPPEROBJECTERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/items/SymbioticObjectErrorMessage.h"

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