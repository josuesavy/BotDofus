#ifndef DICEROLLREQUESTMESSAGE_H
#define DICEROLLREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class DiceRollRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DiceRollRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DiceRollRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DiceRollRequestMessage(FuncTree tree);
  DiceRollRequestMessage();

  uint dice;
  uint faces;
  uint channel;

private:
  void _diceFunc(Reader *input);
  void _facesFunc(Reader *input);
  void _channelFunc(Reader *input);
};

#endif // DICEROLLREQUESTMESSAGE_H