#ifndef UPDATELIFEPOINTSMESSAGE_H
#define UPDATELIFEPOINTSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class UpdateLifePointsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateLifePointsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateLifePointsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateLifePointsMessage(FuncTree tree);
  UpdateLifePointsMessage();

  uint lifePoints;
  uint maxLifePoints;

private:
  void _lifePointsFunc(Reader *input);
  void _maxLifePointsFunc(Reader *input);
};

#endif // UPDATELIFEPOINTSMESSAGE_H