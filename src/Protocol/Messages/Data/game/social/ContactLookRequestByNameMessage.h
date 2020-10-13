#ifndef CONTACTLOOKREQUESTBYNAMEMESSAGE_H
#define CONTACTLOOKREQUESTBYNAMEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/ContactLookRequestMessage.h"

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