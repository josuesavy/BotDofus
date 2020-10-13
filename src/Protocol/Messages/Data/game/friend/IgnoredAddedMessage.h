#ifndef IGNOREDADDEDMESSAGE_H
#define IGNOREDADDEDMESSAGE_H

#include "src/Protocol/Types/Data/game/friend/IgnoredInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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