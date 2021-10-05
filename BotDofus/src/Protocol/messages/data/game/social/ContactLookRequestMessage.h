#ifndef CONTACTLOOKREQUESTMESSAGE_H
#define CONTACTLOOKREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ContactLookRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ContactLookRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ContactLookRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ContactLookRequestMessage(FuncTree tree);
  ContactLookRequestMessage();

  uint requestId;
  uint contactType;

private:
  void _requestIdFunc(Reader *input);
  void _contactTypeFunc(Reader *input);
};

#endif // CONTACTLOOKREQUESTMESSAGE_H