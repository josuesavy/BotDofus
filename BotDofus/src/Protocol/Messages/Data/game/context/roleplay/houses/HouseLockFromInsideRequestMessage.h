#ifndef HOUSELOCKFROMINSIDEREQUESTMESSAGE_H
#define HOUSELOCKFROMINSIDEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/lockable/LockableChangeCodeMessage.h"

class HouseLockFromInsideRequestMessage : public LockableChangeCodeMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseLockFromInsideRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseLockFromInsideRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseLockFromInsideRequestMessage(FuncTree tree);
  HouseLockFromInsideRequestMessage();
};

#endif // HOUSELOCKFROMINSIDEREQUESTMESSAGE_H