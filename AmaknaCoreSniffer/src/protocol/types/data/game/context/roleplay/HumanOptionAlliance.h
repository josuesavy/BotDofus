#ifndef HUMANOPTIONALLIANCE_H
#define HUMANOPTIONALLIANCE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/AllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HumanOptionAlliance : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionAlliance(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionAlliance(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionAlliance(FuncTree tree);
  HumanOptionAlliance();
  bool operator==(const HumanOptionAlliance &compared);

  QSharedPointer<AllianceInformations> allianceInformations;
  uint aggressable;

private:
  void _allianceInformationstreeFunc(Reader *input);
  void _aggressableFunc(Reader *input);

  FuncTree _allianceInformationstree;
};

#endif // HUMANOPTIONALLIANCE_H