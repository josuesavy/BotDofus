#ifndef STARTEXCHANGETAXCOLLECTOREQUIPMENTMESSAGE_H
#define STARTEXCHANGETAXCOLLECTOREQUIPMENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartExchangeTaxCollectorEquipmentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartExchangeTaxCollectorEquipmentMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartExchangeTaxCollectorEquipmentMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartExchangeTaxCollectorEquipmentMessage(FuncTree tree);
  StartExchangeTaxCollectorEquipmentMessage();

  double uid;

private:
  void _uidFunc(Reader *input);
};

#endif // STARTEXCHANGETAXCOLLECTOREQUIPMENTMESSAGE_H