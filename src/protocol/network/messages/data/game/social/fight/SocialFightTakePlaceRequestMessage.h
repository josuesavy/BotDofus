#ifndef SOCIALFIGHTTAKEPLACEREQUESTMESSAGE_H
#define SOCIALFIGHTTAKEPLACEREQUESTMESSAGE_H

#include "src/protocol/types/data/game/social/fight/SocialFightInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class SocialFightTakePlaceRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialFightTakePlaceRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialFightTakePlaceRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialFightTakePlaceRequestMessage(FuncTree tree);
  SocialFightTakePlaceRequestMessage();

  SocialFightInfo socialFightInfo;
  double replacedCharacterId;

private:
  void _socialFightInfotreeFunc(Reader *input);
  void _replacedCharacterIdFunc(Reader *input);

  FuncTree _socialFightInfotree;
};

#endif // SOCIALFIGHTTAKEPLACEREQUESTMESSAGE_H