#ifndef GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H
#define GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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