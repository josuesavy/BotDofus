#ifndef CONTACTLOOKREQUESTBYIDMESSAGE_H
#define CONTACTLOOKREQUESTBYIDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/social/ContactLookRequestMessage.h"

class ContactLookRequestByIdMessage : public ContactLookRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ContactLookRequestByIdMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ContactLookRequestByIdMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ContactLookRequestByIdMessage(FuncTree tree);
  ContactLookRequestByIdMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // CONTACTLOOKREQUESTBYIDMESSAGE_H