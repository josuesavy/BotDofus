#ifndef MOUNTINFORMATIONSFORPADDOCK_H
#define MOUNTINFORMATIONSFORPADDOCK_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class MountInformationsForPaddock : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountInformationsForPaddock(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountInformationsForPaddock(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountInformationsForPaddock(FuncTree tree);
  MountInformationsForPaddock();
  bool operator==(const MountInformationsForPaddock &compared);

  uint modelId;
  QString name;
  QString ownerName;

private:
  void _modelIdFunc(Reader *input);
  void _nameFunc(Reader *input);
  void _ownerNameFunc(Reader *input);
};

#endif // MOUNTINFORMATIONSFORPADDOCK_H