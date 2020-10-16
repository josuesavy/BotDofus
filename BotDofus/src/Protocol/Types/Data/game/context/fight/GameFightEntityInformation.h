#ifndef GAMEFIGHTENTITYINFORMATION_H
#define GAMEFIGHTENTITYINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightEntityInformation : public GameFightFighterInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightEntityInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightEntityInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightEntityInformation(FuncTree tree);
  GameFightEntityInformation();
  bool operator==(const GameFightEntityInformation &compared);

  uint entityModelId;
  uint level;
  double masterId;

private:
  void _entityModelIdFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _masterIdFunc(Reader *input);
};

#endif // GAMEFIGHTENTITYINFORMATION_H