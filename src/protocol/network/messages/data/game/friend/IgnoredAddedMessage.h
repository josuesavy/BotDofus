#ifndef IGNOREDADDEDMESSAGE_H
#define IGNOREDADDEDMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/friend/IgnoredInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class IgnoredAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredAddedMessage(FuncTree tree);
  IgnoredAddedMessage();

  QSharedPointer<IgnoredInformations> ignoreAdded;
  bool session;

private:
  void _ignoreAddedtreeFunc(Reader *input);
  void _sessionFunc(Reader *input);

  FuncTree _ignoreAddedtree;
};

#endif // IGNOREDADDEDMESSAGE_H