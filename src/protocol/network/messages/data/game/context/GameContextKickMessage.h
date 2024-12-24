#ifndef GAMECONTEXTKICKMESSAGE_H
#define GAMECONTEXTKICKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameContextKickMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextKickMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextKickMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextKickMessage(FuncTree tree);
  GameContextKickMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // GAMECONTEXTKICKMESSAGE_H