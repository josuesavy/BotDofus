#ifndef CONTACTLOOKREQUESTMESSAGE_H
#define CONTACTLOOKREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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