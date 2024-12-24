#ifndef UPDATEMOUNTCHARACTERISTICSMESSAGE_H
#define UPDATEMOUNTCHARACTERISTICSMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/mount/UpdateMountCharacteristic.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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