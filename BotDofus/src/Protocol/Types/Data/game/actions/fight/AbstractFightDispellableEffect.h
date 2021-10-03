#ifndef ABSTRACTFIGHTDISPELLABLEEFFECT_H
#define ABSTRACTFIGHTDISPELLABLEEFFECT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AbstractFightDispellableEffect : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractFightDispellableEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractFightDispellableEffect(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractFightDispellableEffect(FuncTree tree);
  AbstractFightDispellableEffect();
  bool operator==(const AbstractFightDispellableEffect &compared);

  uint uid;
  double targetId;
  int turnDuration;
  uint dispelable;
  uint spellId;
  uint effectId;
  uint parentBoostUid;

private:
  void _uidFunc(Reader *input);
  void _targetIdFunc(Reader *input);
  void _turnDurationFunc(Reader *input);
  void _dispelableFunc(Reader *input);
  void _spellIdFunc(Reader *input);
  void _effectIdFunc(Reader *input);
  void _parentBoostUidFunc(Reader *input);
};

#endif // ABSTRACTFIGHTDISPELLABLEEFFECT_H