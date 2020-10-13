#ifndef GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightFighterTaxCollectorLightInformations : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightFighterTaxCollectorLightInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightFighterTaxCollectorLightInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightFighterTaxCollectorLightInformations(FuncTree tree);
  GameFightFighterTaxCollectorLightInformations();
  bool operator==(const GameFightFighterTaxCollectorLightInformations &compared);

  uint firstNameId;
  uint lastNameId;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
};

#endif // GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS_H