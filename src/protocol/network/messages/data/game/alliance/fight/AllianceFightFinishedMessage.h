#ifndef ALLIANCEFIGHTFINISHEDMESSAGE_H
#define ALLIANCEFIGHTFINISHEDMESSAGE_H

#include "src/protocol/types/data/game/social/fight/SocialFightInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceFightFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFightFinishedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFightFinishedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFightFinishedMessage(FuncTree tree);
  AllianceFightFinishedMessage();

  SocialFightInfo allianceFightInfo;

private:
  void _allianceFightInfotreeFunc(Reader *input);

  FuncTree _allianceFightInfotree;
};

#endif // ALLIANCEFIGHTFINISHEDMESSAGE_H