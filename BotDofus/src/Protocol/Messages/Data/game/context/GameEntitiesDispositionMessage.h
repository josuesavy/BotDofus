#ifndef GAMEENTITIESDISPOSITIONMESSAGE_H
#define GAMEENTITIESDISPOSITIONMESSAGE_H

#include "src/Protocol/Types/Data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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