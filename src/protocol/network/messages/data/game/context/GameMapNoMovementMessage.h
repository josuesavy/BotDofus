#ifndef GAMEMAPNOMOVEMENTMESSAGE_H
#define GAMEMAPNOMOVEMENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameMapNoMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapNoMovementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapNoMovementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapNoMovementMessage(FuncTree tree);
  GameMapNoMovementMessage();

  int cellX;
  int cellY;

private:
  void _cellXFunc(Reader *input);
  void _cellYFunc(Reader *input);
};

#endif // GAMEMAPNOMOVEMENTMESSAGE_H