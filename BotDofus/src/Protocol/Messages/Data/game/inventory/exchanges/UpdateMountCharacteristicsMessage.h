#ifndef UPDATEMOUNTCHARACTERISTICSMESSAGE_H
#define UPDATEMOUNTCHARACTERISTICSMESSAGE_H

#include "src/Protocol/Types/Data/game/mount/UpdateMountCharacteristic.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class UpdateMountCharacteristicsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateMountCharacteristicsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateMountCharacteristicsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateMountCharacteristicsMessage(FuncTree tree);
  UpdateMountCharacteristicsMessage();

  int rideId;
  QList<QSharedPointer<UpdateMountCharacteristic>> boostToUpdateList;

private:
  void _rideIdFunc(Reader *input);
  void _boostToUpdateListtreeFunc(Reader *input);
  void _boostToUpdateListFunc(Reader *input);

  FuncTree _boostToUpdateListtree;
};

#endif // UPDATEMOUNTCHARACTERISTICSMESSAGE_H