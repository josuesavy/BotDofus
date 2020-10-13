#ifndef GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE_H
#define GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameMapChangeOrientationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameMapChangeOrientationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameMapChangeOrientationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameMapChangeOrientationRequestMessage(FuncTree tree);
  GameMapChangeOrientationRequestMessage();

  uint direction;

private:
  void _directionFunc(Reader *input);
};

#endif // GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE_H