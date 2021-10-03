#ifndef CONTACTADDFAILUREMESSAGE_H
#define CONTACTADDFAILUREMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ContactAddFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ContactAddFailureMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ContactAddFailureMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ContactAddFailureMessage(FuncTree tree);
  ContactAddFailureMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // CONTACTADDFAILUREMESSAGE_H