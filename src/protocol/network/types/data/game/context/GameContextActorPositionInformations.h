#ifndef GAMECONTEXTACTORPOSITIONINFORMATIONS_H
#define GAMECONTEXTACTORPOSITIONINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class GameContextActorPositionInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextActorPositionInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextActorPositionInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextActorPositionInformations(FuncTree tree);
  GameContextActorPositionInformations();
  bool operator==(const GameContextActorPositionInformations &compared);

  double contextualId;
  QSharedPointer<EntityDispositionInformations> disposition;

private:
  void _contextualIdFunc(Reader *input);
  void _dispositiontreeFunc(Reader *input);

  FuncTree _dispositiontree;
};

#endif // GAMECONTEXTACTORPOSITIONINFORMATIONS_H