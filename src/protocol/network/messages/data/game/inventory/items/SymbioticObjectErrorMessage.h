#ifndef SYMBIOTICOBJECTERRORMESSAGE_H
#define SYMBIOTICOBJECTERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/items/ObjectErrorMessage.h"

class SymbioticObjectErrorMessage : public ObjectErrorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SymbioticObjectErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SymbioticObjectErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SymbioticObjectErrorMessage(FuncTree tree);
  SymbioticObjectErrorMessage();

  int errorCode;

private:
  void _errorCodeFunc(Reader *input);
};

#endif // SYMBIOTICOBJECTERRORMESSAGE_H