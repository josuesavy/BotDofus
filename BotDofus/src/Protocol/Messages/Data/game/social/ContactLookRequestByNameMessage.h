#ifndef CONTACTLOOKREQUESTBYNAMEMESSAGE_H
#define CONTACTLOOKREQUESTBYNAMEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/social/ContactLookRequestMessage.h"

class ContactLookRequestByNameMessage : public ContactLookRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ContactLookRequestByNameMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ContactLookRequestByNameMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ContactLookRequestByNameMessage(FuncTree tree);
  ContactLookRequestByNameMessage();

  QString playerName;

private:
  void _playerNameFunc(Reader *input);
};

#endif // CONTACTLOOKREQUESTBYNAMEMESSAGE_H