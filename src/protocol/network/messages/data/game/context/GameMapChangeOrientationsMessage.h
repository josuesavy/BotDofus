#ifndef GAMEMAPCHANGEORIENTATIONSMESSAGE_H
#define GAMEMAPCHANGEORIENTATIONSMESSAGE_H

#include "src/protocol/network/types/data/game/context/ActorOrientation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameMapChangeOrientationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapChangeOrientationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapChangeOrientationsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapChangeOrientationsMessage(FuncTree tree);
  GameMapChangeOrientationsMessage();

  QList<ActorOrientation> orientations;

private:
  void _orientationstreeFunc(Reader *input);
  void _orientationsFunc(Reader *input);

  FuncTree _orientationstree;
};

#endif // GAMEMAPCHANGEORIENTATIONSMESSAGE_H