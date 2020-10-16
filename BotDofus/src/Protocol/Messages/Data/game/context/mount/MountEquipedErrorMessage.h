#ifndef MOUNTEQUIPEDERRORMESSAGE_H
#define MOUNTEQUIPEDERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MountEquipedErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountEquipedErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountEquipedErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountEquipedErrorMessage(FuncTree tree);
  MountEquipedErrorMessage();

  uint errorType;

private:
  void _errorTypeFunc(Reader *input);
};

#endif // MOUNTEQUIPEDERRORMESSAGE_H