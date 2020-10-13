#ifndef SYMBIOTICOBJECTASSOCIATEDMESSAGE_H
#define SYMBIOTICOBJECTASSOCIATEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SymbioticObjectAssociatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SymbioticObjectAssociatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SymbioticObjectAssociatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SymbioticObjectAssociatedMessage(FuncTree tree);
  SymbioticObjectAssociatedMessage();

  uint hostUID;

private:
  void _hostUIDFunc(Reader *input);
};

#endif // SYMBIOTICOBJECTASSOCIATEDMESSAGE_H