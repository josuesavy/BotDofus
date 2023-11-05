#ifndef UPDATEMOUNTINTEGERCHARACTERISTIC_H
#define UPDATEMOUNTINTEGERCHARACTERISTIC_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/mount/UpdateMountCharacteristic.h"
#include "src/engines/io/network/utils/FuncTree.h"

class UpdateMountIntegerCharacteristic : public UpdateMountCharacteristic
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateMountIntegerCharacteristic(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateMountIntegerCharacteristic(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateMountIntegerCharacteristic(FuncTree tree);
  UpdateMountIntegerCharacteristic();
  bool operator==(const UpdateMountIntegerCharacteristic &compared);

  int value;

private:
  void _valueFunc(Reader *input);
};

#endif // UPDATEMOUNTINTEGERCHARACTERISTIC_H