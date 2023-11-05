#ifndef ALLIANCEINFORMATION_H
#define ALLIANCEINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/social/SocialEmblem.h"
#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AllianceInformation : public BasicNamedAllianceInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInformation(FuncTree tree);
  AllianceInformation();
  bool operator==(const AllianceInformation &compared);

  SocialEmblem allianceEmblem;

private:
  void _allianceEmblemtreeFunc(Reader *input);

  FuncTree _allianceEmblemtree;
};

#endif // ALLIANCEINFORMATION_H