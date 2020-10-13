#ifndef GAMEMAPCHANGEORIENTATIONSMESSAGE_H
#define GAMEMAPCHANGEORIENTATIONSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/ActorOrientation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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