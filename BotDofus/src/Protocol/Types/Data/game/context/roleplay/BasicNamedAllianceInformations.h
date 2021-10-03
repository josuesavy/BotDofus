#ifndef BASICNAMEDALLIANCEINFORMATIONS_H
#define BASICNAMEDALLIANCEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class BasicNamedAllianceInformations : public BasicAllianceInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicNamedAllianceInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicNamedAllianceInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicNamedAllianceInformations(FuncTree tree);
  BasicNamedAllianceInformations();
  bool operator==(const BasicNamedAllianceInformations &compared);

  QString allianceName;

private:
  void _allianceNameFunc(Reader *input);
};

#endif // BASICNAMEDALLIANCEINFORMATIONS_H