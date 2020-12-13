#ifndef SETUPDATEMESSAGE_H
#define SETUPDATEMESSAGE_H

#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class SetUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SetUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SetUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SetUpdateMessage(FuncTree tree);
  SetUpdateMessage();

  uint setId;
  QList<uint> setObjects;
  QList<QSharedPointer<ObjectEffect>> setEffects;

private:
  void _setIdFunc(Reader *input);
  void _setObjectstreeFunc(Reader *input);
  void _setObjectsFunc(Reader *input);
  void _setEffectstreeFunc(Reader *input);
  void _setEffectsFunc(Reader *input);

  FuncTree _setObjectstree;
  FuncTree _setEffectstree;
};

#endif // SETUPDATEMESSAGE_H