#ifndef GAMEENTITIESDISPOSITIONMESSAGE_H
#define GAMEENTITIESDISPOSITIONMESSAGE_H

#include "src/protocol/types/data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameEntitiesDispositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameEntitiesDispositionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameEntitiesDispositionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameEntitiesDispositionMessage(FuncTree tree);
  GameEntitiesDispositionMessage();

  QList<QSharedPointer<IdentifiedEntityDispositionInformations>> dispositions;

private:
  void _dispositionstreeFunc(Reader *input);
  void _dispositionsFunc(Reader *input);

  FuncTree _dispositionstree;
};

#endif // GAMEENTITIESDISPOSITIONMESSAGE_H