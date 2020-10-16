#ifndef BASICALLIANCEINFORMATIONS_H
#define BASICALLIANCEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/social/AbstractSocialGroupInfos.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class BasicAllianceInformations : public AbstractSocialGroupInfos
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicAllianceInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicAllianceInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicAllianceInformations(FuncTree tree);
  BasicAllianceInformations();
  bool operator==(const BasicAllianceInformations &compared);

  uint allianceId;
  QString allianceTag;

private:
  void _allianceIdFunc(Reader *input);
  void _allianceTagFunc(Reader *input);
};

#endif // BASICALLIANCEINFORMATIONS_H