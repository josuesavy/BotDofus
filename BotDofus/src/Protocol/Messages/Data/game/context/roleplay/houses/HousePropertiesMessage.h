#ifndef HOUSEPROPERTIESMESSAGE_H
#define HOUSEPROPERTIESMESSAGE_H

#include "src/protocol/types/data/game/house/HouseInstanceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class HousePropertiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HousePropertiesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HousePropertiesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HousePropertiesMessage(FuncTree tree);
  HousePropertiesMessage();

  uint houseId;
  QList<uint> doorsOnMap;
  QSharedPointer<HouseInstanceInformations> properties;

private:
  void _houseIdFunc(Reader *input);
  void _doorsOnMaptreeFunc(Reader *input);
  void _doorsOnMapFunc(Reader *input);
  void _propertiestreeFunc(Reader *input);

  FuncTree _doorsOnMaptree;
  FuncTree _propertiestree;
};

#endif // HOUSEPROPERTIESMESSAGE_H