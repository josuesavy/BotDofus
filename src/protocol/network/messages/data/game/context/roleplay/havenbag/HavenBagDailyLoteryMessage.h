#ifndef HAVENBAGDAILYLOTERYMESSAGE_H
#define HAVENBAGDAILYLOTERYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HavenBagDailyLoteryMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagDailyLoteryMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagDailyLoteryMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagDailyLoteryMessage(FuncTree tree);
  HavenBagDailyLoteryMessage();

  uint returnType;
  QString gameActionId;

private:
  void _returnTypeFunc(Reader *input);
  void _gameActionIdFunc(Reader *input);
};

#endif // HAVENBAGDAILYLOTERYMESSAGE_H