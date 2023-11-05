#ifndef ALLIANCELISTAPPLICATIONMODIFIEDMESSAGE_H
#define ALLIANCELISTAPPLICATIONMODIFIEDMESSAGE_H

#include "src/protocol/types/data/game/social/application/SocialApplicationInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceListApplicationModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceListApplicationModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceListApplicationModifiedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceListApplicationModifiedMessage(FuncTree tree);
  AllianceListApplicationModifiedMessage();

  SocialApplicationInformation apply;
  uint state;
  double playerId;

private:
  void _applytreeFunc(Reader *input);
  void _stateFunc(Reader *input);
  void _playerIdFunc(Reader *input);

  FuncTree _applytree;
};

#endif // ALLIANCELISTAPPLICATIONMODIFIEDMESSAGE_H