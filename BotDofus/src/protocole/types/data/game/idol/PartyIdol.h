#ifndef PARTYIDOL_H
#define PARTYIDOL_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/idol/Idol.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PartyIdol : public Idol
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyIdol(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyIdol(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyIdol(FuncTree tree);
  PartyIdol();
  bool operator==(const PartyIdol &compared);

  QList<double> ownersIds;

private:
  void _ownersIdstreeFunc(Reader *input);
  void _ownersIdsFunc(Reader *input);

  FuncTree _ownersIdstree;
};

#endif // PARTYIDOL_H