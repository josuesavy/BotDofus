#ifndef PRESET_H
#define PRESET_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class Preset : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Preset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Preset(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Preset(FuncTree tree);
  Preset();
  bool operator==(const Preset &compared);

  int id;

private:
  void _idFunc(Reader *input);
};

#endif // PRESET_H