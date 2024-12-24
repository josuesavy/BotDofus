#ifndef GAMEENTITYDISPOSITIONERRORMESSAGE_H
#define GAMEENTITYDISPOSITIONERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameEntityDispositionErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameEntityDispositionErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameEntityDispositionErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameEntityDispositionErrorMessage(FuncTree tree);
  GameEntityDispositionErrorMessage();
};

#endif // GAMEENTITYDISPOSITIONERRORMESSAGE_H