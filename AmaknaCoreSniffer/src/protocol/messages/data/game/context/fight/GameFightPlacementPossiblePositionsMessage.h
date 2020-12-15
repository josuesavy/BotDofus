#ifndef GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE_H
#define GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameFightPlacementPossiblePositionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementPossiblePositionsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementPossiblePositionsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementPossiblePositionsMessage(FuncTree tree);
  GameFightPlacementPossiblePositionsMessage();

  QList<uint> positionsForChallengers;
  QList<uint> positionsForDefenders;
  uint teamNumber;

private:
  void _positionsForChallengerstreeFunc(Reader *input);
  void _positionsForChallengersFunc(Reader *input);
  void _positionsForDefenderstreeFunc(Reader *input);
  void _positionsForDefendersFunc(Reader *input);
  void _teamNumberFunc(Reader *input);

  FuncTree _positionsForChallengerstree;
  FuncTree _positionsForDefenderstree;
};

#endif // GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE_H