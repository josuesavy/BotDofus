#ifndef ALLIANCEINFORMATIONS_H
#define ALLIANCEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/GuildEmblem.h"
#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AllianceInformations : public BasicNamedAllianceInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInformations(FuncTree tree);
  AllianceInformations();
  bool operator==(const AllianceInformations &compared);

  GuildEmblem allianceEmblem;

private:
  void _allianceEmblemtreeFunc(Reader *input);

  FuncTree _allianceEmblemtree;
};

#endif // ALLIANCEINFORMATIONS_H