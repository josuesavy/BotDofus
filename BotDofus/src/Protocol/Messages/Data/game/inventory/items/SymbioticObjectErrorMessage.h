#ifndef SYMBIOTICOBJECTERRORMESSAGE_H
#define SYMBIOTICOBJECTERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/items/ObjectErrorMessage.h"

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