#ifndef CONTACTLOOKERRORMESSAGE_H
#define CONTACTLOOKERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ContactLookErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ContactLookErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ContactLookErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ContactLookErrorMessage(FuncTree tree);
  ContactLookErrorMessage();

  uint requestId;

private:
  void _requestIdFunc(Reader *input);
};

#endif // CONTACTLOOKERRORMESSAGE_H