#ifndef SHORTCUT_H
#define SHORTCUT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class Shortcut : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Shortcut(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Shortcut(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Shortcut(FuncTree tree);
  Shortcut();
  bool operator==(const Shortcut &compared);

  uint slot;

private:
  void _slotFunc(Reader *input);
};

#endif // SHORTCUT_H