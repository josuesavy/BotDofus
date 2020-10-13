#ifndef OBJECTEFFECTDICE_H
#define OBJECTEFFECTDICE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectEffectDice : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectDice(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectDice(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectDice(FuncTree tree);
  ObjectEffectDice();
  bool operator==(const ObjectEffectDice &compared);

  uint diceNum;
  uint diceSide;
  uint diceConst;

private:
  void _diceNumFunc(Reader *input);
  void _diceSideFunc(Reader *input);
  void _diceConstFunc(Reader *input);
};

#endif // OBJECTEFFECTDICE_H