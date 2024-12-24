#ifndef GAMEFIGHTLEAVEMESSAGE_H
#define GAMEFIGHTLEAVEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightLeaveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightLeaveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightLeaveMessage(FuncTree tree);
  GameFightLeaveMessage();

  double charId;

private:
  void _charIdFunc(Reader *input);
};

#endif // GAMEFIGHTLEAVEMESSAGE_H