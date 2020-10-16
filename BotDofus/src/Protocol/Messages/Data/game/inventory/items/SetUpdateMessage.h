#ifndef SETUPDATEMESSAGE_H
#define SETUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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