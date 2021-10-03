#ifndef FIGHTENTITYDISPOSITIONINFORMATIONS_H
#define FIGHTENTITYDISPOSITIONINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

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