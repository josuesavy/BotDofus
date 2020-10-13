#ifndef ALLIANCEMODIFICATIONVALIDMESSAGE_H
#define ALLIANCEMODIFICATIONVALIDMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceModificationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceModificationValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceModificationValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceModificationValidMessage(FuncTree tree);
  AllianceModificationValidMessage();

  QString allianceName;
  QString allianceTag;
  GuildEmblem Alliancemblem;

private:
  void _allianceNameFunc(Reader *input);
  void _allianceTagFunc(Reader *input);
  void _AlliancemblemtreeFunc(Reader *input);

  FuncTree _Alliancemblemtree;
};

#endif // ALLIANCEMODIFICATIONVALIDMESSAGE_H