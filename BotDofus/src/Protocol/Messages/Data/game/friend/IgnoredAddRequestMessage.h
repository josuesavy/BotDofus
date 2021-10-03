#ifndef IGNOREDADDREQUESTMESSAGE_H
#define IGNOREDADDREQUESTMESSAGE_H

#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  QSharedPointer<AbstractPlayerSearchInformation> target;
  bool session;

private:
  void _targettreeFunc(Reader *input);
  void _sessionFunc(Reader *input);

  FuncTree _targettree;
};

#endif // IGNOREDADDREQUESTMESSAGE_H