#ifndef ALLIANCEINFORMATIONS_H
#define ALLIANCEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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