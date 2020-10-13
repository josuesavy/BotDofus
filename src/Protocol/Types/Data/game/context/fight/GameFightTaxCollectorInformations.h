#ifndef GAMEFIGHTTAXCOLLECTORINFORMATIONS_H
#define GAMEFIGHTTAXCOLLECTORINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightAIInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightTaxCollectorInformations : public GameFightAIInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTaxCollectorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTaxCollectorInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTaxCollectorInformations(FuncTree tree);
  GameFightTaxCollectorInformations();
  bool operator==(const GameFightTaxCollectorInformations &compared);

  uint firstNameId;
  uint lastNameId;
  uint level;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _levelFunc(Reader *input);
};

#endif // GAMEFIGHTTAXCOLLECTORINFORMATIONS_H