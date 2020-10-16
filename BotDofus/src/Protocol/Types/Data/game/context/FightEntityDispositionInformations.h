#ifndef FIGHTENTITYDISPOSITIONINFORMATIONS_H
#define FIGHTENTITYDISPOSITIONINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightEntityDispositionInformations : public EntityDispositionInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightEntityDispositionInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightEntityDispositionInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightEntityDispositionInformations(FuncTree tree);
  FightEntityDispositionInformations();
  bool operator==(const FightEntityDispositionInformations &compared);

  double carryingCharacterId;

private:
  void _carryingCharacterIdFunc(Reader *input);
};

#endif // FIGHTENTITYDISPOSITIONINFORMATIONS_H