#ifndef PRISMSINFOVALIDMESSAGE_H
#define PRISMSINFOVALIDMESSAGE_H

#include "src/protocol/types/data/game/prism/PrismFightersInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismsInfoValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismsInfoValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismsInfoValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismsInfoValidMessage(FuncTree tree);
  PrismsInfoValidMessage();

  QList<QSharedPointer<PrismFightersInformation>> fights;

private:
  void _fightstreeFunc(Reader *input);
  void _fightsFunc(Reader *input);

  FuncTree _fightstree;
};

#endif // PRISMSINFOVALIDMESSAGE_H