#ifndef UPDATEMOUNTBOOLEANCHARACTERISTIC_H
#define UPDATEMOUNTBOOLEANCHARACTERISTIC_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/mount/UpdateMountCharacteristic.h"
#include "src/engines/io/network/utils/FuncTree.h"

class UpdateMountBooleanCharacteristic : public UpdateMountCharacteristic
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateMountBooleanCharacteristic(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateMountBooleanCharacteristic(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateMountBooleanCharacteristic(FuncTree tree);
  UpdateMountBooleanCharacteristic();
  bool operator==(const UpdateMountBooleanCharacteristic &compared);

  bool value;

private:
  void _valueFunc(Reader *input);
};

#endif // UPDATEMOUNTBOOLEANCHARACTERISTIC_H