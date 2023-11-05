#ifndef ALLIANCEMODIFICATIONVALIDMESSAGE_H
#define ALLIANCEMODIFICATIONVALIDMESSAGE_H

#include "src/protocol/types/data/game/social/SocialEmblem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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
  SocialEmblem allianceEmblem;

private:
  void _allianceNameFunc(Reader *input);
  void _allianceTagFunc(Reader *input);
  void _allianceEmblemtreeFunc(Reader *input);

  FuncTree _allianceEmblemtree;
};

#endif // ALLIANCEMODIFICATIONVALIDMESSAGE_H