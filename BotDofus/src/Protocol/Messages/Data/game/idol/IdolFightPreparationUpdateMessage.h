#ifndef IDOLFIGHTPREPARATIONUPDATEMESSAGE_H
#define IDOLFIGHTPREPARATIONUPDATEMESSAGE_H

#include "src/protocol/types/data/game/idol/Idol.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class IdolFightPreparationUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolFightPreparationUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolFightPreparationUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolFightPreparationUpdateMessage(FuncTree tree);
  IdolFightPreparationUpdateMessage();

  uint idolSource;
  QList<QSharedPointer<Idol>> idols;

private:
  void _idolSourceFunc(Reader *input);
  void _idolstreeFunc(Reader *input);
  void _idolsFunc(Reader *input);

  FuncTree _idolstree;
};

#endif // IDOLFIGHTPREPARATIONUPDATEMESSAGE_H