#ifndef GAMEROLEPLAYSHOWMULTIPLEACTORSMESSAGE_H
#define GAMEROLEPLAYSHOWMULTIPLEACTORSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayShowMultipleActorsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayShowMultipleActorsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayShowMultipleActorsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayShowMultipleActorsMessage(FuncTree tree);
  GameRolePlayShowMultipleActorsMessage();

  QList<QSharedPointer<GameRolePlayActorInformations>> informationsList;

private:
  void _informationsListtreeFunc(Reader *input);
  void _informationsListFunc(Reader *input);

  FuncTree _informationsListtree;
};

#endif // GAMEROLEPLAYSHOWMULTIPLEACTORSMESSAGE_H