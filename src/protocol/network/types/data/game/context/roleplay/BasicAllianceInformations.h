#ifndef BASICALLIANCEINFORMATIONS_H
#define BASICALLIANCEINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/social/AbstractSocialGroupInfos.h"
#include "src/utils/io/type/FuncTree.h"

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