#ifndef ACQUAINTANCEADDEDMESSAGE_H
#define ACQUAINTANCEADDEDMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/friend/AcquaintanceInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AcquaintanceAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintanceAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintanceAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintanceAddedMessage(FuncTree tree);
  AcquaintanceAddedMessage();

  QSharedPointer<AcquaintanceInformation> acquaintanceAdded;

private:
  void _acquaintanceAddedtreeFunc(Reader *input);

  FuncTree _acquaintanceAddedtree;
};

#endif // ACQUAINTANCEADDEDMESSAGE_H