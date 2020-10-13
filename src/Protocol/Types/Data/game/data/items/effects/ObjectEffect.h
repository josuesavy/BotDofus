#ifndef OBJECTEFFECT_H
#define OBJECTEFFECT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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