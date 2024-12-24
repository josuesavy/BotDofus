#ifndef MOODSMILEYUPDATEMESSAGE_H
#define MOODSMILEYUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MoodSmileyUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MoodSmileyUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MoodSmileyUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MoodSmileyUpdateMessage(FuncTree tree);
  MoodSmileyUpdateMessage();

  uint accountId;
  double playerId;
  uint smileyId;

private:
  void _accountIdFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _smileyIdFunc(Reader *input);
};

#endif // MOODSMILEYUPDATEMESSAGE_H