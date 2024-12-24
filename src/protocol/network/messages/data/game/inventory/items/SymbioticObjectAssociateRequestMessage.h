#ifndef SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE_H
#define SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SymbioticObjectAssociateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SymbioticObjectAssociateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SymbioticObjectAssociateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SymbioticObjectAssociateRequestMessage(FuncTree tree);
  SymbioticObjectAssociateRequestMessage();

  uint symbioteUID;
  uint symbiotePos;
  uint hostUID;
  uint hostPos;

private:
  void _symbioteUIDFunc(Reader *input);
  void _symbiotePosFunc(Reader *input);
  void _hostUIDFunc(Reader *input);
  void _hostPosFunc(Reader *input);
};

#endif // SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE_H