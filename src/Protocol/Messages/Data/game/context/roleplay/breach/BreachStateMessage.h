#ifndef BREACHSTATEMESSAGE_H
#define BREACHSTATEMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterMinimalInformations.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BreachStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachStateMessage(FuncTree tree);
  BreachStateMessage();

  CharacterMinimalInformations owner;
  QList<QSharedPointer<ObjectEffectInteger>> bonuses;
  uint bugdet;
  bool saved;

private:
  void _ownertreeFunc(Reader *input);
  void _bonusestreeFunc(Reader *input);
  void _bonusesFunc(Reader *input);
  void _bugdetFunc(Reader *input);
  void _savedFunc(Reader *input);

  FuncTree _ownertree;
  FuncTree _bonusestree;
};

#endif // BREACHSTATEMESSAGE_H