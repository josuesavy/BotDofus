#ifndef ALLIANCECREATIONVALIDMESSAGE_H
#define ALLIANCECREATIONVALIDMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceCreationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceCreationValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceCreationValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceCreationValidMessage(FuncTree tree);
  AllianceCreationValidMessage();

  QString allianceName;
  QString allianceTag;
  GuildEmblem allianceEmblem;

private:
  void _allianceNameFunc(Reader *input);
  void _allianceTagFunc(Reader *input);
  void _allianceEmblemtreeFunc(Reader *input);

  FuncTree _allianceEmblemtree;
};

#endif // ALLIANCECREATIONVALIDMESSAGE_H