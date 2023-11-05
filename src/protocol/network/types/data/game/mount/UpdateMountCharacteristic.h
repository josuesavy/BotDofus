#ifndef UPDATEMOUNTCHARACTERISTIC_H
#define UPDATEMOUNTCHARACTERISTIC_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class UpdateMountCharacteristic : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateMountCharacteristic(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateMountCharacteristic(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateMountCharacteristic(FuncTree tree);
  UpdateMountCharacteristic();
  bool operator==(const UpdateMountCharacteristic &compared);

  uint type;

private:
  void _typeFunc(Reader *input);
};

#endif // UPDATEMOUNTCHARACTERISTIC_H