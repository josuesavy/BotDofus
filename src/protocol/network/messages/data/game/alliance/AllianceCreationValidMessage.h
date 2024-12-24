#ifndef ALLIANCECREATIONVALIDMESSAGE_H
#define ALLIANCECREATIONVALIDMESSAGE_H

#include "src/protocol/network/types/data/game/social/SocialEmblem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
  SocialEmblem allianceEmblem;

private:
  void _allianceNameFunc(Reader *input);
  void _allianceTagFunc(Reader *input);
  void _allianceEmblemtreeFunc(Reader *input);

  FuncTree _allianceEmblemtree;
};

#endif // ALLIANCECREATIONVALIDMESSAGE_H