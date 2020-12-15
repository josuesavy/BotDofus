#ifndef GAMEFIGHTTURNFINISHMESSAGE_H
#define GAMEFIGHTTURNFINISHMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameFightTurnFinishMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnFinishMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnFinishMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnFinishMessage(FuncTree tree);
  GameFightTurnFinishMessage();

  bool isAfk;

private:
  void _isAfkFunc(Reader *input);
};

#endif // GAMEFIGHTTURNFINISHMESSAGE_H