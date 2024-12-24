#ifndef SETUPDATEMESSAGE_H
#define SETUPDATEMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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