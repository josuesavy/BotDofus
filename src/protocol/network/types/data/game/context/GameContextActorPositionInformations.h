#ifndef GAMECONTEXTACTORPOSITIONINFORMATIONS_H
#define GAMECONTEXTACTORPOSITIONINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

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
   disposition;

private:
  void _contextualIdFunc(Reader *input);
  void _dispositiontreeFunc(Reader *input);

  FuncTree _dispositiontree;
};

#endif // GAMECONTEXTACTORPOSITIONINFORMATIONS_H