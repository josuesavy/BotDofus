#ifndef IDOLPARTYREGISTERREQUESTMESSAGE_H
#define IDOLPARTYREGISTERREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class IdolPartyRegisterRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolPartyRegisterRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolPartyRegisterRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolPartyRegisterRequestMessage(FuncTree tree);
  IdolPartyRegisterRequestMessage();

  bool m_register;

private:
  void _registerFunc(Reader *input);
};

#endif // IDOLPARTYREGISTERREQUESTMESSAGE_H
