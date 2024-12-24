#ifndef CONTACTLOOKMESSAGE_H
#define CONTACTLOOKMESSAGE_H

#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ContactLookMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ContactLookMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ContactLookMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ContactLookMessage(FuncTree tree);
  ContactLookMessage();

  uint requestId;
  QString playerName;
  double playerId;
  QSharedPointer<EntityLook> look;

private:
  void _requestIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _looktreeFunc(Reader *input);

  FuncTree _looktree;
};

#endif // CONTACTLOOKMESSAGE_H