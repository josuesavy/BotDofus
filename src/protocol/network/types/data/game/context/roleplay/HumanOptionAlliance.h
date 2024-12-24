#ifndef HUMANOPTIONALLIANCE_H
#define HUMANOPTIONALLIANCE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOption.h"
#include "src/utils/io/type/FuncTree.h"

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

  QSharedPointer<AllianceInformation> allianceInformation;
  uint aggressable;

private:
  void _allianceInformationtreeFunc(Reader *input);
  void _aggressableFunc(Reader *input);

  FuncTree _allianceInformationtree;
};

#endif // HUMANOPTIONALLIANCE_H