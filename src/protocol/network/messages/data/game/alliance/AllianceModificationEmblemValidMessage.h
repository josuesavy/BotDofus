#ifndef ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE_H
#define ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE_H

#include "src/protocol/types/data/game/social/SocialEmblem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceModificationEmblemValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceModificationEmblemValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceModificationEmblemValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceModificationEmblemValidMessage(FuncTree tree);
  AllianceModificationEmblemValidMessage();

  SocialEmblem allianceEmblem;

private:
  void _allianceEmblemtreeFunc(Reader *input);

  FuncTree _allianceEmblemtree;
};

#endif // ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE_H