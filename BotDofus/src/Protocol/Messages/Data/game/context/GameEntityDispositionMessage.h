#ifndef GAMEENTITYDISPOSITIONMESSAGE_H
#define GAMEENTITYDISPOSITIONMESSAGE_H

#include "src/protocol/types/data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameEntityDispositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameEntityDispositionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameEntityDispositionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameEntityDispositionMessage(FuncTree tree);
  GameEntityDispositionMessage();

  QSharedPointer<IdentifiedEntityDispositionInformations> disposition;

private:
  void _dispositiontreeFunc(Reader *input);

  FuncTree _dispositiontree;
};

#endif // GAMEENTITYDISPOSITIONMESSAGE_H