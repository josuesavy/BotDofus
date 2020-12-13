#ifndef IDOLPARTYREFRESHMESSAGE_H
#define IDOLPARTYREFRESHMESSAGE_H

#include "src/protocol/types/data/game/idol/PartyIdol.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class IdolPartyRefreshMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolPartyRefreshMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolPartyRefreshMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolPartyRefreshMessage(FuncTree tree);
  IdolPartyRefreshMessage();

  QSharedPointer<PartyIdol> partyIdol;

private:
  void _partyIdoltreeFunc(Reader *input);

  FuncTree _partyIdoltree;
};

#endif // IDOLPARTYREFRESHMESSAGE_H