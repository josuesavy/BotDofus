#ifndef OBJECTEFFECT_H
#define OBJECTEFFECT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ObjectEffect : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffect(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffect(FuncTree tree);
  ObjectEffect();
  bool operator==(const ObjectEffect &compared);

  uint actionId;

private:
  void _actionIdFunc(Reader *input);
};

#endif // OBJECTEFFECT_H