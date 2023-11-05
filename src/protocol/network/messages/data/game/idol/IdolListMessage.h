#ifndef IDOLLISTMESSAGE_H
#define IDOLLISTMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/idol/PartyIdol.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class IdolListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolListMessage(FuncTree tree);
  IdolListMessage();

  QList<uint> chosenIdols;
  QList<uint> partyChosenIdols;
  QList<QSharedPointer<PartyIdol>> partyIdols;

private:
  void _chosenIdolstreeFunc(Reader *input);
  void _chosenIdolsFunc(Reader *input);
  void _partyChosenIdolstreeFunc(Reader *input);
  void _partyChosenIdolsFunc(Reader *input);
  void _partyIdolstreeFunc(Reader *input);
  void _partyIdolsFunc(Reader *input);

  FuncTree _chosenIdolstree;
  FuncTree _partyChosenIdolstree;
  FuncTree _partyIdolstree;
};

#endif // IDOLLISTMESSAGE_H