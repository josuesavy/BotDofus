#ifndef CONTACTADDFAILUREMESSAGE_H
#define CONTACTADDFAILUREMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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