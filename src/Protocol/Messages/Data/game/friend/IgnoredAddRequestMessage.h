#ifndef IGNOREDADDREQUESTMESSAGE_H
#define IGNOREDADDREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class IgnoredAddRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredAddRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredAddRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredAddRequestMessage(FuncTree tree);
  IgnoredAddRequestMessage();

  QString name;
  bool session;

private:
  void _nameFunc(Reader *input);
  void _sessionFunc(Reader *input);
};

#endif // IGNOREDADDREQUESTMESSAGE_H