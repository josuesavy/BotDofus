#ifndef GAMEFIGHTFIGHTERENTITYLIGHTINFORMATION_H
#define GAMEFIGHTFIGHTERENTITYLIGHTINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightFighterEntityLightInformation : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightFighterEntityLightInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightFighterEntityLightInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightFighterEntityLightInformation(FuncTree tree);
  GameFightFighterEntityLightInformation();
  bool operator==(const GameFightFighterEntityLightInformation &compared);

  uint entityModelId;
  double masterId;

private:
  void _entityModelIdFunc(Reader *input);
  void _masterIdFunc(Reader *input);
};

#endif // GAMEFIGHTFIGHTERENTITYLIGHTINFORMATION_H