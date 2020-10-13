#ifndef UPDATEMOUNTINTEGERCHARACTERISTIC_H
#define UPDATEMOUNTINTEGERCHARACTERISTIC_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/mount/UpdateMountCharacteristic.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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