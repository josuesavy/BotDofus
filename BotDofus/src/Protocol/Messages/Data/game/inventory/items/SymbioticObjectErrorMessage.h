#ifndef SYMBIOTICOBJECTERRORMESSAGE_H
#define SYMBIOTICOBJECTERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/ObjectErrorMessage.h"

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