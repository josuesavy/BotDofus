#ifndef GAMEMAPCHANGEORIENTATIONMESSAGE_H
#define GAMEMAPCHANGEORIENTATIONMESSAGE_H

#include "src/protocol/types/data/game/context/ActorOrientation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameMapChangeOrientationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapChangeOrientationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapChangeOrientationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapChangeOrientationMessage(FuncTree tree);
  GameMapChangeOrientationMessage();

  ActorOrientation orientation;

private:
  void _orientationtreeFunc(Reader *input);

  FuncTree _orientationtree;
};

#endif // GAMEMAPCHANGEORIENTATIONMESSAGE_H