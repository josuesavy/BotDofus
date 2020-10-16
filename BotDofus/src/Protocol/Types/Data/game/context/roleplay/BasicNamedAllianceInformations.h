#ifndef BASICNAMEDALLIANCEINFORMATIONS_H
#define BASICNAMEDALLIANCEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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