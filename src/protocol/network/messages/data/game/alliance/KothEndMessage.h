#ifndef KOTHENDMESSAGE_H
#define KOTHENDMESSAGE_H

#include "src/protocol/types/data/game/alliance/KothWinner.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class KothEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KothEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KothEndMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KothEndMessage(FuncTree tree);
  KothEndMessage();

  KothWinner winner;

private:
  void _winnertreeFunc(Reader *input);

  FuncTree _winnertree;
};

#endif // KOTHENDMESSAGE_H