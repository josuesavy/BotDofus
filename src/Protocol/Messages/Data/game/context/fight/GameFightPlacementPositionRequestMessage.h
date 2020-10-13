#ifndef GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H
#define GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightPlacementPositionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementPositionRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementPositionRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementPositionRequestMessage(FuncTree tree);
  GameFightPlacementPositionRequestMessage();

  uint cellId;

private:
  void _cellIdFunc(Reader *input);
};

#endif // GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H